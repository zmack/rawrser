#include <string.h>
#include <malloc.h>
#include <stdio.h>

%%{
  machine foo;

  action ac_mark_current { last_position = fpc; }
  action ac_timestamp { printf("Timestamp! %s\n", string_from_positions(last_position, fpc)); }
  action ac_path { printf("Path: %s\n", string_from_positions(last_position, fpc-1)); }
  action ac_pid { printf("Pid: %s\n", string_from_positions(last_position, fpc)); }
  action ac_ip { printf("Ip: %s\n", string_from_positions(last_position, fpc)); }

  timestamp = digit{4} "-" digit{2} "-" digit{2} " " digit{2} ":" digit{2} ":" digit{2};
  pid = "[" digit+ "]";
  method = ( "GET" | "POST" | "PUT" | "DELETE" );
  ip = digit{1,3} "." digit{1,3} "." digit{1,3} "." digit{1,3};

  main := timestamp >ac_mark_current @ac_timestamp" " pid >ac_mark_current @ac_pid
          " Started " method ' "' (!'"'+ '"') >ac_mark_current @ac_path  " for "
          (ip ' ') >ac_mark_current @ac_ip any+ 
    0 @ { res = 1; };
}%%

%% write data;


char * string_from_positions(const char *initial, const char *current) {
  unsigned int string_length = current - initial + 1;
  char *string = (char *)malloc(string_length + 1);
  strncpy(string, initial, string_length);

  return string;
};


int main( int argc, char **argv) {
  int cs, res = 0;
  char *last_position;

  if ( argc > 1 ) {
    char *p = argv[1];
    char *pe = p + strlen(p) + 1;
    %% write init;
    %% write exec;
  }

  printf("Result for %s is %d\n", argv[1], res);
  return 0;
}
