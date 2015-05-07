
#line 1 "csv.rl"
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


#line 68 "csv.rl"



#line 31 "csv.c"
static const char _csv_actions[] = {
	0, 1, 0, 1, 2, 2, 0, 1, 
	2, 1, 2, 2, 2, 0, 3, 1, 
	2, 0
};

static const char _csv_key_offsets[] = {
	0, 1, 2, 4, 6
};

static const char _csv_trans_keys[] = {
	44, 44, 10, 44, 10, 44, 10, 44, 
	0
};

static const char _csv_single_lengths[] = {
	1, 1, 2, 2, 2
};

static const char _csv_range_lengths[] = {
	0, 0, 0, 0, 0
};

static const char _csv_index_offsets[] = {
	0, 2, 4, 7, 10
};

static const char _csv_trans_targs[] = {
	2, 1, 2, 1, 4, 2, 3, 4, 
	2, 3, 4, 2, 3, 0
};

static const char _csv_trans_actions[] = {
	3, 11, 0, 1, 14, 8, 14, 5, 
	0, 1, 5, 0, 1, 0
};

static const int csv_start = 0;
static const int csv_first_final = 4;
static const int csv_error = -1;

static const int csv_en_main = 0;


#line 71 "csv.rl"

void csv_init( struct csvdata *data ) {
  data->buflen = 0;
  
#line 81 "csv.c"
	{
	 data->cs = csv_start;
	}

#line 75 "csv.rl"
}

void csv_exec( struct csvdata *data, const char *d, int len )
{
  const char *p = d;
  const char *pe = d + len;

  
#line 95 "csv.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
_resume:
	_keys = _csv_trans_keys + _csv_key_offsets[ data->cs];
	_trans = _csv_index_offsets[ data->cs];

	_klen = _csv_single_lengths[ data->cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _csv_range_lengths[ data->cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	 data->cs = _csv_trans_targs[_trans];

	if ( _csv_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _csv_actions + _csv_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 28 "csv.rl"
	{
    if ( data->buflen < MAX_BUF_LEN )
      data->buffer[ data->buflen++ ] = (*p);
  }
	break;
	case 1:
#line 34 "csv.rl"
	{
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
	break;
	case 2:
#line 60 "csv.rl"
	{ data->buflen = 0; }
	break;
#line 204 "csv.c"
		}
	}

_again:
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	}

#line 83 "csv.rl"
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
  char buf[ MAX_BUF_LEN + 1 ] = {"\0"}

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
