/* files.ale */

#include "stddata.h"
#include "files.h"
#include "lexical.h"
#include "display.h"
#include "symbols.h"
#include "tags.h"
#include "types.h"
#include "pragmats.h"
#include "disc.h"

/* ===================================================================== */
/* messages */
static int
no_external_string,tag_redefined_at,tag_redefined_proto,mixing_proto,
no_external_init,no_file_path,must_be_of_list_type,tag_expected,
too_many_datafile_area,tag_expected_for;

#define addMSG(x,y) add_new_string(x,MESSAGE);y=MESSAGE->aupb

static void add_messages(void){
  addMSG("external %p declaration: missing string after %p=",no_external_string);
  addMSG("%p: redefined as %p (was %p at %l)",tag_redefined_at);
  addMSG("%p: redefined as %p (was %p)",tag_redefined_proto);
  addMSG("mixing declaration and prototype in %p declaration",mixing_proto);
  addMSG("external %p declaration: missing = after %p",no_external_init);
  addMSG("missing path in file declaration",no_file_path);
  addMSG("file are %p must be of list type (%p)",must_be_of_list_type);
  addMSG("list tag is expected in file area",tag_expected);
  addMSG("too many datafile area (max %d)",too_many_datafile_area);
  addMSG("%p declaration: tag expected",tag_expected_for);
}
#undef addMSG

static void tagRedefined(int *a){/* >tag+>newtype */
  int par[5];int l,oldtype;
  par[0]=a[0];getDefline(par);l=par[1];getType(par);oldtype=par[1];
  if(l>0){par[0]=tag_redefined_at;par[1]=a[0];par[2]=a[1];
    par[3]=oldtype;par[4]=l;Error(5,par);}
  else{par[0]=tag_redefined_proto;par[1]=a[0];par[2]=a[1];
    par[3]=oldtype;Error(4,par);}
}
/* ===================================================================== */
static void expectPath(int *a){/* >tag+path>+dir> */
  int par[3];
  a[2]=0;par[0]=Sright;if(R(par)){a[2]++;}
  if(isString(par)){a[1]=par[0];}
  else{a[1]=Squoteimage;par[0]=no_file_path;par[1]=a[0];Error(2,par);}
  par[0]=a[1];newStdstring(par);a[1]=par[1];
  par[0]=Sright;if(R(par)){a[2]+=2;}
}
//static void Dtyper(int *a){ /* >type */
//  int par[2];
//  if(a[0]==Icharfile){par[0]=Dcharfile;D(par);}
//  else{par[0]=Ddatafile;D(par);}
//}
#define maxDatafileArea  32
static void fileArea(void){
  int par[3];int tag,type,cnt;
  cnt=0;nxt:if(isTag(par)){tag=par[0];cnt++;par[0]=tag;Dtag(par);
    par[0]=tag;getTagHash(par);par[0]=par[1];Dcons(par);
    par[0]=tag;getType(par);type=par[1];
    if(type==Iempty||type==Itable||type==Istack||type==IstaticStack)
       {par[0]=tag;useTag(par);}
    else{par[0]=must_be_of_list_type;par[1]=tag;par[2]=type;Error(3,par);}}
  else{par[0]=tag_expected;Error(1,par);}
  if(cnt==maxDatafileArea){par[0]=too_many_datafile_area;
    par[1]=maxDatafileArea;Error(2,par);}
  par[0]=Ssemicolon;if(R(par)){goto nxt;}
  par[0]=Sbus;must(par);
}
static void fileAreaDeclarer(int *a){/* >tag+>dl */
  int par[3]; int err,path,dir;
  err=0;par[0]=a[0];getType(par);if(par[1]==Iempty){;}
  else if(par[1]==Idatafile){;}
  else{par[0]=a[0];par[1]=Idatafile;tagRedefined(par);err=1;}
  par[0]=a[0];par[1]=a[1];par[2]=err;addTagDefinition(par);err=par[2];
  if(err){;}else{par[0]=a[0];par[1]=Idatafile;putType(par);}
  par[0]=Dfile;D(par);par[0]=a[0];Dtag(par);par[0]=Dsub;D(par);
  fileArea();par[0]=Dbus;D(par);par[0]=Sequals;must(par);
  par[0]=a[0];expectPath(par);path=par[1];dir=par[2];par[0]=dir;Dcons(par);
  par[0]=Xstringtable;Dtag(par);par[0]=path;Dtag(par);par[0]=Dpoint;D(par);
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
static void declarer(int *a){/* >tag+>type+>dl */
  int par[3];int path,err,dir;
  err=0;par[0]=a[0];getType(par);if(par[1]==Iempty){;}
  else if(par[1]==a[1]){;}
  else{par[0]=a[0];par[1]=a[1];tagRedefined(par);err=1;}
  par[0]=a[0];par[1]=a[2];par[2]=err;addTagDefinition(par);err=par[2];
  if(err){;}else{par[0]=a[0];par[1]=a[1];putType(par);}
  par[0]=a[0];expectPath(par);path=par[1];dir=par[2];
  par[0]=Dfile;D(par);par[0]=a[0];Dtag(par);par[0]=dir;
  Dcons(par);par[0]=Xstringtable;Dtag(par);
  par[0]=path;Dtag(par);par[0]=Dpoint;D(par);
}
static void externalDeclarer(int *a){/* >tag+>type+>dl */
  int par[3];int str,err;
  err=0;par[0]=a[0];getType(par);if(par[1]==Iempty){;}
  else if(par[1]==a[1]){;}
  else{par[0]=a[0];par[1]=a[1];tagRedefined(par);err=1;}
  if(isString(par)){str=par[0];}
  else{str=0;err=1;par[0]=no_external_string;par[1]=a[1];par[2]=a[0];
    Error(3,par);skipAll();}
  par[0]=a[0];par[1]=a[2];par[2]=err;addTagExternal(par);err=par[2];
  if(err){;}else{par[0]=a[0];par[1]=a[1];putType(par);par[0]=a[0];
    par[1]=str;putRepr(par);}
}
static void prototype(int *a){ /* >tag + >type + >dl */
  int par[3];int proto,err;
  par[0]=pgtProto;getPragmatValue(par);proto=par[1];
  par[0]=a[0];getType(par);err=0;if(par[1]==Iempty){;}
  else if(par[1]==a[1]){;}
  else{par[0]=a[0];par[1]=a[1];tagRedefined(par);err=1;}
  if(err){;}
  else if(proto==1){par[0]=a[0];par[1]=a[2];par[2]=err;
    addTagImport(par);err=par[2];}
  else if(proto==2){par[0]=a[0];par[1]=a[2];par[2]=err;
    addTagPublic(par);err=par[2];}
  else{par[0]=a[0];par[1]=a[2];addTagPrototype(par);}
  if(err){;}else{par[0]=a[0];par[1]=a[1];putType(par);}
}
static void declaration(int *a){ /* >ext> + >type */
  int par[3];int tag,dl;
  if(isTagdl(par)){tag=par[0];dl=par[1];par[0]=Sequals;
    if(R(par)){if(a[0]==3){par[0]=mixing_proto;par[1]=a[1];
        Error(2,par);skipAll();}
      else if(a[0]==1){par[0]=tag;par[1]=a[1];par[2]=dl;
        externalDeclarer(par);}
      else{a[0]=1;par[0]=tag;par[1]=a[1];par[2]=dl;declarer(par);}}
    else if(a[0]==1){par[0]=no_external_init;par[1]=a[1];
      par[2]=tag;Error(3,par);skipAll();}
    else if(a[1]==Idatafile &&(par[0]=Ssub,R(par))){
      if(a[0]==3){par[0]=mixing_proto;par[1]=a[1];Error(2,par);
        skipAll();}
      else{a[0]=2;par[0]=tag;par[1]=dl;fileAreaDeclarer(par);}}
    else if(a[0]==2){par[0]=mixing_proto;par[1]=a[1];Error(2,par);
      skipAll();}
    else{a[0]=3;par[0]=tag;par[1]=a[1];par[2]=dl;prototype(par);}}
  else{par[0]=tag_expected_for;par[1]=a[1];Error(2,par);skipAll();}
}
static void declarationSeries(int *a){ /* >ext+>type */
  int par[2];nxt:
  par[0]=a[0];par[1]=a[1];declaration(par);a[0]=par[0];
  par[0]=Scomma;if(R(par)){goto nxt;}
  par[0]=Spoint;if(R(par)){;}
  else{par[0]=Spoint;must(par);skipToPoint();}
}
/* --------------------------------------------------------------------- */
void datafileDeclaration(int *a) {/* >ext */
  int par[2];
  par[0]=a[0];par[1]=Idatafile;declarationSeries(par);
}
void charfileDeclaration(int *a){ /* >ext */
  int par[2];
  par[0]=a[0];par[1]=Icharfile;declarationSeries(par);
}
/* --------------------------------------------------------------------- */

void initialize_files(void){
  add_messages();
}

/* EOF */

