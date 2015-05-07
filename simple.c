
#line 1 "simple.rl"
#include <string.h>
#include <malloc.h>
#include <stdio.h>


#line 23 "simple.rl"



#line 13 "simple.c"
static const char _foo_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5, 2, 0, 2
	
};

static const unsigned char _foo_key_offsets[] = {
	0, 0, 2, 4, 6, 8, 9, 11, 
	13, 14, 16, 18, 19, 21, 23, 24, 
	26, 28, 29, 31, 33, 34, 35, 37, 
	40, 41, 42, 43, 44, 45, 46, 47, 
	48, 49, 52, 53, 54, 55, 56, 57, 
	58, 59, 60, 61, 63, 65, 67, 69, 
	71, 74, 78, 81, 85, 88, 92, 95, 
	99, 100, 102, 105, 108, 111, 114, 117, 
	121, 126, 130, 135, 139, 144, 148, 153, 
	158, 161, 166, 169, 174, 177, 182, 185, 
	189, 191, 195, 197, 201, 203, 207, 209, 
	210, 211, 212, 214, 215
};

static const char _foo_trans_keys[] = {
	48, 57, 48, 57, 48, 57, 48, 57, 
	45, 48, 57, 48, 57, 45, 48, 57, 
	48, 57, 32, 48, 57, 48, 57, 58, 
	48, 57, 48, 57, 58, 48, 57, 48, 
	57, 32, 91, 48, 57, 93, 48, 57, 
	32, 83, 116, 97, 114, 116, 101, 100, 
	32, 68, 71, 80, 69, 76, 69, 84, 
	69, 32, 34, 34, 34, 32, 34, 34, 
	102, 34, 111, 34, 114, 32, 34, 34, 
	48, 57, 34, 46, 48, 57, 34, 48, 
	57, 34, 46, 48, 57, 34, 48, 57, 
	34, 46, 48, 57, 34, 48, 57, 32, 
	34, 48, 57, 34, 0, 34, 0, 32, 
	34, 0, 34, 102, 0, 34, 111, 0, 
	34, 114, 0, 32, 34, 0, 34, 48, 
	57, 0, 34, 46, 48, 57, 0, 34, 
	48, 57, 0, 34, 46, 48, 57, 0, 
	34, 48, 57, 0, 34, 46, 48, 57, 
	0, 34, 48, 57, 0, 32, 34, 48, 
	57, 0, 32, 34, 48, 57, 0, 32, 
	34, 0, 34, 46, 48, 57, 0, 34, 
	46, 0, 34, 46, 48, 57, 0, 34, 
	46, 0, 34, 46, 48, 57, 0, 34, 
	46, 32, 34, 48, 57, 32, 34, 34, 
	46, 48, 57, 34, 46, 34, 46, 48, 
	57, 34, 46, 34, 46, 48, 57, 34, 
	46, 32, 69, 84, 79, 85, 83, 0, 
	34, 0
};

static const char _foo_single_lengths[] = {
	0, 0, 0, 0, 0, 1, 0, 0, 
	1, 0, 0, 1, 0, 0, 1, 0, 
	0, 1, 0, 0, 1, 1, 0, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 3, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 2, 2, 2, 2, 2, 
	1, 2, 1, 2, 1, 2, 1, 2, 
	1, 2, 3, 3, 3, 3, 3, 2, 
	3, 2, 3, 2, 3, 2, 3, 3, 
	3, 3, 3, 3, 3, 3, 3, 2, 
	2, 2, 2, 2, 2, 2, 2, 1, 
	1, 1, 2, 1, 2
};

static const char _foo_range_lengths[] = {
	0, 1, 1, 1, 1, 0, 1, 1, 
	0, 1, 1, 0, 1, 1, 0, 1, 
	1, 0, 1, 1, 0, 0, 1, 1, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	0, 0, 0, 0, 0, 0, 0, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	0, 1, 0, 1, 0, 1, 0, 1, 
	0, 1, 0, 1, 0, 1, 0, 0, 
	0, 0, 0, 0, 0
};

static const short _foo_index_offsets[] = {
	0, 0, 2, 4, 6, 8, 10, 12, 
	14, 16, 18, 20, 22, 24, 26, 28, 
	30, 32, 34, 36, 38, 40, 42, 44, 
	47, 49, 51, 53, 55, 57, 59, 61, 
	63, 65, 69, 71, 73, 75, 77, 79, 
	81, 83, 85, 87, 90, 93, 96, 99, 
	102, 105, 109, 112, 116, 119, 123, 126, 
	130, 132, 135, 139, 143, 147, 151, 155, 
	159, 164, 168, 173, 177, 182, 186, 191, 
	196, 200, 205, 209, 214, 218, 223, 227, 
	231, 234, 238, 241, 245, 248, 252, 255, 
	257, 259, 261, 264, 266
};

static const char _foo_indicies[] = {
	0, 1, 2, 1, 3, 1, 4, 1, 
	5, 1, 6, 1, 7, 1, 8, 1, 
	9, 1, 10, 1, 11, 1, 12, 1, 
	13, 1, 14, 1, 15, 1, 16, 1, 
	17, 1, 18, 1, 19, 1, 20, 1, 
	21, 1, 22, 1, 23, 22, 1, 24, 
	1, 25, 1, 26, 1, 27, 1, 28, 
	1, 29, 1, 30, 1, 31, 1, 32, 
	1, 33, 34, 35, 1, 36, 1, 37, 
	1, 38, 1, 39, 1, 40, 1, 41, 
	1, 42, 1, 44, 43, 46, 45, 47, 
	46, 45, 46, 48, 45, 46, 49, 45, 
	46, 50, 45, 51, 46, 45, 46, 52, 
	45, 46, 53, 54, 45, 46, 55, 45, 
	46, 56, 57, 45, 46, 58, 45, 46, 
	59, 60, 45, 46, 61, 45, 62, 46, 
	63, 45, 65, 64, 66, 65, 64, 66, 
	67, 65, 64, 66, 65, 68, 64, 66, 
	65, 69, 64, 66, 65, 70, 64, 66, 
	71, 65, 64, 66, 65, 72, 64, 66, 
	65, 73, 74, 64, 66, 65, 75, 64, 
	66, 65, 76, 77, 64, 66, 65, 78, 
	64, 66, 65, 79, 80, 64, 66, 65, 
	81, 64, 66, 82, 65, 83, 64, 66, 
	82, 65, 84, 64, 66, 82, 65, 64, 
	66, 65, 79, 85, 64, 66, 65, 79, 
	64, 66, 65, 76, 86, 64, 66, 65, 
	76, 64, 66, 65, 73, 87, 64, 66, 
	65, 73, 64, 62, 46, 88, 45, 62, 
	46, 45, 46, 59, 89, 45, 46, 59, 
	45, 46, 56, 90, 45, 46, 56, 45, 
	46, 53, 91, 45, 46, 53, 45, 47, 
	45, 92, 1, 40, 1, 93, 92, 1, 
	92, 1, 66, 65, 64, 0
};

static const char _foo_trans_targs[] = {
	2, 0, 3, 4, 5, 6, 7, 8, 
	9, 10, 11, 12, 13, 14, 15, 16, 
	17, 18, 19, 20, 21, 22, 23, 24, 
	25, 26, 27, 28, 29, 30, 31, 32, 
	33, 34, 88, 90, 35, 36, 37, 38, 
	39, 40, 41, 42, 87, 42, 43, 44, 
	45, 46, 47, 48, 49, 50, 85, 51, 
	52, 83, 53, 54, 81, 55, 56, 79, 
	57, 58, 92, 59, 60, 61, 62, 63, 
	64, 65, 77, 66, 67, 75, 68, 69, 
	73, 70, 57, 71, 72, 74, 76, 78, 
	80, 82, 84, 86, 89, 91
};

static const char _foo_trans_actions[] = {
	1, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 3, 0, 1, 0, 7, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 1, 13, 0, 5, 0, 
	0, 0, 0, 0, 1, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 9, 0, 
	0, 5, 11, 0, 0, 0, 0, 0, 
	1, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 9, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0
};

static const int foo_start = 1;
static const int foo_first_final = 92;
static const int foo_error = 0;

static const int foo_en_main = 1;


#line 26 "simple.rl"


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
    
#line 205 "simple.c"
	{
	cs = foo_start;
	}

#line 45 "simple.rl"
    
#line 212 "simple.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _foo_trans_keys + _foo_key_offsets[cs];
	_trans = _foo_index_offsets[cs];

	_klen = _foo_single_lengths[cs];
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

	_klen = _foo_range_lengths[cs];
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
	_trans = _foo_indicies[_trans];
	cs = _foo_trans_targs[_trans];

	if ( _foo_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _foo_actions + _foo_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 8 "simple.rl"
	{ last_position = p; }
	break;
	case 1:
#line 9 "simple.rl"
	{ printf("Timestamp! %s\n", string_from_positions(last_position, p)); }
	break;
	case 2:
#line 10 "simple.rl"
	{ printf("Path: %s\n", string_from_positions(last_position, p-1)); }
	break;
	case 3:
#line 11 "simple.rl"
	{ printf("Pid: %s\n", string_from_positions(last_position, p)); }
	break;
	case 4:
#line 12 "simple.rl"
	{ printf("Ip: %s\n", string_from_positions(last_position, p)); }
	break;
	case 5:
#line 22 "simple.rl"
	{ res = 1; }
	break;
#line 310 "simple.c"
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	_out: {}
	}

#line 46 "simple.rl"
  }

  printf("Result for %s is %d\n", argv[1], res);
  return 0;
}
