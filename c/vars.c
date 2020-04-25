/* vars.ale */

#include "stddata.h"
#include "vars.h"
#include "display.h"
#include "lexical.h"
#include "symbols.h"
#include "tags.h"
#include "pragmats.h"
#include "types.h"
#include "disc.h"

/* -------------------------------------------------------------------- */
/* messages */
static int wrong_expression,tag_expected,wrong_or_missing_expression,
  tag_expected_for,tag_is_not_list_type,tag_is_not_constant_type,
  no_external_tag,no_external_init,no_external_string,mixing_proto,
  tag_redefined_at,tag_redefined_proto,virtual_bounds_only;


#define addMSG(x,y) add_new_string(x,MESSAGE);y=MESSAGE->aupb
static void add_messages(void){
 addMSG("wrong expression syntax",wrong_expression);
 addMSG("in expression a tag is expected",tag_expected);
 addMSG("wrong or missing expression",wrong_or_missing_expression);
 addMSG("tag expected for '%p'",tag_expected_for);
 addMSG("tag %p must be table or stack (%p)",tag_is_not_list_type);
 addMSG("tag %p must be a constant (%p)",tag_is_not_constant_type);
 addMSG("%p: no external tag in expression",no_external_tag);
 addMSG("external %p declaration: missing = after %p",no_external_init);
 addMSG("external %p declaration: missing string after %p=",no_external_string);
 addMSG("mixing declaration and prototype in %p declaration",mixing_proto);
 addMSG("%p: redefined as %p (was %p at %l)",tag_redefined_at);
 addMSG("%p: redefined as %p (was %p)",tag_redefined_proto);
 addMSG("only virtual bounds in expressions",virtual_bounds_only);
}
#undef addMSG

static void tagRedefined(int *a){/* >tag+>newtype */
  int par[5];int l,oldtype;
  par[0]=a[0];getDefline(par);l=par[1];getType(par);oldtype=par[1];
  if(l>0){par[0]=tag_redefined_at;par[1]=a[0];par[2]=a[1];par[3]=oldtype;
    par[4]=l;Error(5,par);}
  else{par[0]=tag_redefined_proto;par[1]=a[0];par[2]=a[1];par[3]=oldtype;
   Error(4,par);}
}
/* ============================================================ */
/* read an expression */
static int exprbase(int *);

static int isExpression(int *a){ /* >err> */
  int par[3];
  par[0]=Sminus;if(R(par)){par[0]=Dminus;D(par);}nxt:
  par[0]=a[0];if(exprbase(par)){a[0]=par[0];
    if(a[0]){;}
    else if(par[0]=Sboolor,R(par)){par[0]=Dor;D(par);goto nxt;}
    else if(par[0]=Sbooland,R(par)){par[0]=Dand;D(par);goto nxt;}
    else if(par[0]=Sboolxor,R(par)){par[0]=Dxor;D(par);goto nxt;}
    else if(par[0]=Splus,R(par)){par[0]=Dplus,D(par);goto nxt;}
    else if(par[0]=Sminus,R(par)){par[0]=Dminus;D(par);goto nxt;}
    else if(aheadCons()){par[0]=Dplus;D(par);goto nxt;}
    else if(par[0]=Sasterisk,R(par)){par[0]=Dstar;D(par);goto nxt;}
    else if(par[0]=Sslash,R(par)){par[0]=Ddiv;D(par);goto nxt;}
  } else{return 0;}
  return 1;
}
static void expectListTag(int *a){ /* >err> */
  int par[3];int x,type;
  if(isTag(par)){x=par[0];getType(par);type=par[1];Dtag(par);
    if(type==Iempty||type==Itable||type==Istack||type==IstaticStack){;}
    else{par[0]=tag_is_not_list_type;par[1]=x;par[2]=type;
      Error(3,par);a[0]=1;}
    par[0]=x;par[1]=texternal;if(isTagFlag(par)){a[0]=1;
      par[0]=no_external_tag;par[1]=x;Error(2,par);}
   if(a[0]){;}else{par[0]=x;useTag(par);}}
  else{a[0]=1;par[0]=tag_expected;Error(1,par);}
}
static void expectConstantTag(int *a){ /* >tag+>err> */
  int par[3];int type;
  par[0]=a[0];getType(par);type=par[1];par[0]=a[0];Dtag(par);
  if(type==Iempty||type==Iconstant||type==IpointerConstant){;}
  else{par[0]=tag_is_not_constant_type;par[1]=a[0];par[2]=type;
//printf("tag=%d,type=%d,expected=%d\n",a[0],type,IpointerConstant);
    Error(3,par);a[1]=1;}
  par[0]=a[0];par[1]=texternal;if(isTagFlag(par)){a[1]=1;
    par[0]=no_external_tag;par[1]=a[0];Error(2,par);}
  if(a[1]){;}else{par[0]=a[0];useTag(par);}
}
static int exprbase(int *a){ /* >err> */
  int par[3];int va[2];
  if(isCons(par)){Dcons(par);}
  else if(isTag(par)){par[1]=a[0];expectConstantTag(par);a[0]=par[1];}
  else if(par[0]=Scomplement,R(par)){par[0]=Dcompl;D(par);par[0]=a[0];
   if(exprbase(par)){a[0]=par[0];}else if(a[0]){;} else{a[0]=1;
    par[0]=wrong_expression;Error(1,par);}}
  else if(par[0]=Svlwb,R(par)){par[0]=Dlwb;D(par);par[0]=a[0];
    expectListTag(par);a[0]=par[0];}
  else if(par[0]=Svupb,R(par)){par[0]=Dupb;D(par);par[0]=a[0];
    expectListTag(par);a[0]=par[0];}
  else if(par[0]=Slwb,R(par)){va[0]=virtual_bounds_only;
    Warning(1,1,va);par[0]=Dlwb;D(par);par[0]=a[0];expectListTag(par);
    a[0]=par[0];}
  else if(par[0]=Supb,R(par)){va[0]=virtual_bounds_only;
    Warning(1,1,va);par[0]=Dupb;D(par);par[0]=a[0];expectListTag(par);
    a[0]=par[0];}
  else if(par[0]=Scalibre,R(par)){par[0]=Dcalibre;D(par);par[0]=a[0];
    expectListTag(par);a[0]=par[0];}
  else if(par[0]=Sopen,R(par)){par[0]=Dopen;D(par);par[0]=a[0];
    if(isExpression(par)){a[0]=par[0];}
    else{a[0]=1;par[0]=wrong_expression;Error(1,par);}
    par[0]=Dclose;D(par);par[0]=Sclose;must(par);}
  else{return 0;}
  return 1;
}
static void expectExpression(int *a){ /* >err> */
  int par[2];
  if(isExpression(a)){;}
  else{a[0]=1;par[0]=wrong_or_missing_expression;Error(1,par);}
  if(a[0]){skipAll();}
}
/* ------------------------------------------------------ */
//static void Dtyper(int *a){ /* >type */
//  int par[2];
//  if(a[0]==Iconstant){ par[0]=Dconstant;D(par);}
//  else if(a[0]==Ivariable){ par[0]=Dvariable;D(par);}
//  else{par[0]=DstaticVar;D(par);}
//}
static void declarer(int *a){ /* >tag + >type + >dl */
  int par[3];int err,otype;
  err=0;par[0]=a[0];getType(par);otype=par[1];
  if(otype==Iempty){;}
  else if(otype==a[1]){;}
  else{par[0]=a[0];par[1]=a[1];tagRedefined(par);err=1;}
  par[0]=a[0];par[1]=a[2];par[2]=err;addTagDefinition(par);
  err=par[2];if(err){;}else{par[0]=a[0];par[1]=a[1];putType(par);}
  par[0]=Dexpression;D(par);par[0]=a[0];Dtag(par);par[0]=err;
  expectExpression(par);par[0]=Dpoint;D(par);
}
static void externalDeclarer(int *a){ /* >tag+>type+>dl */
  int par[3];int str,err,otype;
  err=0;par[0]=a[0];getType(par);otype=par[1];
  if(otype==Iempty||otype==a[1]){;}
  else{par[0]=a[0];par[1]=a[1];tagRedefined(par);err=1;}
  if(isString(par)){str=par[0];}
  else{str=0;err=1;par[0]=no_external_string;par[1]=a[1];par[2]=a[0];
    Error(3,par);skipAll();}
  par[0]=a[0];par[1]=a[2];par[2]=err;addTagExternal(par);err=par[2];
  if(err){;}else{par[0]=a[0];par[1]=a[1];putType(par);par[0]=a[0];
    par[1]=str;putRepr(par);}
}
static void prototype(int *a){ /* >tag+>type+>dl */
  int par[3];int proto,otype,err;
  par[0]=pgtProto;getPragmatValue(par);proto=par[1];
//  if(a[1]==IstaticVar&&proto==1){a[1]=IstaticConst;}
  par[0]=a[0];getType(par);otype=par[1];err=0;
  if(otype==Iempty||otype==a[1]){;}
  else{par[0]=a[0];par[1]=a[1];tagRedefined(par);err=1;}
  if(err){;}
  else if(proto==1){par[0]=a[0];par[1]=a[2];par[2]=err;addTagImport(par);err=par[2];}
  else if(proto==2){par[0]=a[0];par[1]=a[2];par[2]=err;addTagPublic(par);err=par[2];}
  else{par[0]=a[0];par[1]=a[2];addTagPrototype(par);}
  if(err){;}else{par[0]=a[0];par[1]=a[1];putType(par);}
//printf("const/var proto=%d,flag=%x ",proto,LADM->offset[a[0]-LADM_flag]);par[0]=a[0];printPointer(par);printf(" ");par[0]=a[0];getType(par);par[0]=par[1];printPointer(par);printf("\n");
}
static void declaration(int *a){/* >ext> + >type */
  int par[4];int tag,dl;
  if(isTagdl(par)){tag=par[0];dl=par[1];par[0]=Sequals;
    if(R(par)){if(a[0]==3){par[0]=mixing_proto;par[1]=a[1];Error(1,par);skipAll();}
      else if(a[0]==1){par[0]=tag;par[1]=a[1];par[2]=dl;externalDeclarer(par);}
      else{a[0]=2;par[0]=tag;par[1]=a[1];par[2]=dl;declarer(par);}}
    else if(a[0]==1){par[0]=no_external_init;par[1]=a[1];par[2]=tag;Error(3,par);skipAll();}
    else if(a[0]==2){par[0]=mixing_proto;par[1]=a[1];Error(2,par);skipAll();}
    else{a[0]=3;par[0]=tag;par[1]=a[1];par[2]=dl;prototype(par);}}
  else{par[0]=tag_expected_for;par[1]=a[1];Error(2,par);skipAll();}
}
static void declarationSeries(int *a){ /* >ext + >type */
  int par[4]; nxt:
  par[0]=a[0];par[1]=a[1];declaration(par);a[0]=par[0];
  par[0]=Scomma;if(R(par)){goto nxt;}
  par[0]=Spoint;if(R(par)){;}
  else{must(par);skipToPoint();}
}
void constantDeclaration(int *a){ /* >ext */
  int par[2];
  par[0]=a[0];par[1]=Iconstant;declarationSeries(par);
}
void variableDeclaration(int *a){ /* >ext */
  int par[2];
  par[0]=a[0];par[1]=Ivariable;declarationSeries(par);
}
void staticVariableDeclaration(void){
  int par[2];
  par[0]=0;par[1]=IstaticVar;declarationSeries(par);
}
/* ---------------------------------------------------- */

void initialize_vars(void){
  add_messages();
}

/* EOF */

