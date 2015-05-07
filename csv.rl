#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX_BUF_LEN  1023

struct csvline {
  char *f1;
  char *f2;
  int   f3;
};

struct csvdata {
  int cs;
  int buflen;
  char buffer[ MAX_BUF_LEN + 1 ];
  int field;
  struct csvline line;
};

void print_data( struct csvdata *data, int lineno );

%%{
  machine csv;
  access data->;

  # Append to the buffer.
  action append {
    if ( data->buflen < MAX_BUF_LEN )
      data->buffer[ data->buflen++ ] = fc;
  }

  # Terminate a buffer.
  action term {
    if ( data->buflen < MAX_BUF_LEN )
      data->buffer[ data->buflen++ ] = 0;

    switch( data->field ) {
      case 0:
        data->line.f1 = (char *)calloc( data->buflen, sizeof( char ) );
        strncpy( data->line.f1, data->buffer, data->buflen );
        data->field++;
        break;
      case 1:
        data->line.f2 = (char *)calloc( data->buflen, sizeof( char ) );
        strncpy( data->line.f2, data->buffer, data->buflen );
        data->field++;
        break;
      case 2:
        data->line.f3 = atoi( data->buffer );
        data->field++;
        break;
      default:
        // ignore
        break;
    }
  }

  # Clear out the buffer
  action clear { data->buflen = 0; }

  # Helpers that collect strings
  LF = "\n";
  string = [^,]* >clear $append;
  string2 = [^,]* >clear $append %term;
  comma = "," %term;
main := ( string comma )+ string2 ? LF;
}%%

%% write data;

void csv_init( struct csvdata *data ) {
  data->buflen = 0;
  %% write init;
}

void csv_exec( struct csvdata *data, const char *d, int len )
{
  const char *p = d;
  const char *pe = d + len;

  %% write exec;
}

int csv_finish( struct csvdata *data )
{
  if ( data->cs == csv_error )
    return -1;
  if ( data->cs >= csv_first_final )
    return 1;
  return 0;
}

#define BUFSIZE 2048

int main( int argc, char **argv )
{
  struct csvdata csvdata;
  FILE *csvfile;
  int lineno = 0;
  char buf[ MAX_BUF_LEN + 1 ] = {"\0"};

  if (( csvfile = fopen( "test.csv", "r" ) ) == NULL ) {
    fprintf( stderr, "Could not open file test.csv\n" );
    return -1;
  }

  while ( fgets( buf, MAX_BUF_LEN, csvfile ) != NULL ) {
    // One more line to process
    memset( &csvdata, 0x00, sizeof( csvdata ));
    csv_exec( &csvdata, buf, strlen( buf ) );
    if ( csv_finish( &csvdata ) != 1 ) {
      fprintf( stderr, "error occurred in line: %d\n", lineno );
    } else {
      print_data( &csvdata, lineno );
    }
    lineno++;
  }

  return 0;
}

void print_data( struct csvdata *data, int lineno ) {
  fprintf( stdout, "[line %d] f1: %s", lineno, data->line.f1 );
  fprintf( stdout, ", f2: %s", data->line.f2 );
  fprintf( stdout, ", f3: %d\n", data->line.f3 );
}
