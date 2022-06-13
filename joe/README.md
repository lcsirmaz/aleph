## Aleph syntax highlighter for joe

Add the file [aleph.jsf](aleph.jsf) to the syntac directory (typically it is /usr/share/joe/syntax/); moreover add the
following lines to the `ftypes` configuration file (typically located in /etc/joe):

     ALEPH
    *.ale
    -syntax aleph
    -autoindent
    -no_double_quoted
    -smarthome
    -highlighter_context

(observe that the title has a leading space, other lines do not).

