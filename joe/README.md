## Aleph syntax highlighter for joe

Add the file [aleph.jsf](aleph.jsf) to the syntax directory (typically it is /usr/share/joe/syntax/); moreover add the
following lines to the `ftypes` configuration file (typically located in /etc/joe/ftypes):

     ALEPH
    *.ale
    -syntax aleph
    -autoindent
    -no_double_quoted
    -smarthome
    -highlighter_context

(Observe that the title ALEPH has a leading space while other lines do not).

