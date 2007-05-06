/* Generated by re2c 0.13.0.dev on Sun May  6 21:32:27 2007 */
#line 1 "scanner.re"
/* $Id$ */
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <stdarg.h>
#include "scanner.h"
#include "parser.h"
#include "y.tab.h"
#include "globals.h"
#include "dfa.h"

extern YYSTYPE yylval;

#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif

#define	BSIZE		8192
#define	YYCTYPE		unsigned char
#define	YYCURSOR	cursor
#define	YYLIMIT		lim
#define	YYMARKER	ptr
#define YYCTXMARKER ctx
#define	YYFILL(n)	{cursor = fill(cursor);}

#define	RETURN(i)	{cur = cursor; return i;}

namespace re2c
{

Scanner::Scanner(std::istream& i, std::ostream& o)
	: in(i)
	, out(o)
	, bot(NULL), tok(NULL), ptr(NULL), cur(NULL), pos(NULL), lim(NULL)
	, top(NULL), eof(NULL), ctx(NULL), tchar(0), tline(0), cline(1), iscfg(0)
{
	;
}

char *Scanner::fill(char *cursor)
{
	if(!eof)
	{
		uint cnt = tok - bot;
		if(cnt)
		{
			memcpy(bot, tok, lim - tok);
			tok = bot;
			ptr -= cnt;
			cursor -= cnt;
			pos -= cnt;
			lim -= cnt;
		}
		if((top - lim) < BSIZE)
		{
			char *buf = new char[(lim - bot) + BSIZE];
			memcpy(buf, tok, lim - tok);
			tok = buf;
			ptr = &buf[ptr - bot];
			cursor = &buf[cursor - bot];
			pos = &buf[pos - bot];
			lim = &buf[lim - bot];
			top = &lim[BSIZE];
			delete [] bot;
			bot = buf;
		}
		in.read(lim, BSIZE);
		if((cnt = in.gcount()) != BSIZE)
		{
			eof = &lim[cnt];
			*eof++ = '\0';
		}
		lim += cnt;
	}
	return cursor;
}

#line 98 "scanner.re"


int Scanner::echo()
{
	char *cursor = cur;
	bool ignore_eoc = false;
	int  ignore_cnt = 0;

	if (eof && cursor == eof) // Catch EOF
	{
		return 0;
	}
	
	tok = cursor;
echo:

#line 99 "scanner.cc"
{
	YYCTYPE yych;
	unsigned int yyaccept = 0;

	if((YYLIMIT - YYCURSOR) < 16) YYFILL(16);
	yych = *YYCURSOR;
	if(yych <= ')') {
		if(yych <= 0x00) goto yy7;
		if(yych == 0x0A) goto yy5;
		goto yy9;
	} else {
		if(yych <= '*') goto yy4;
		if(yych != '/') goto yy9;
	}
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych == '*') goto yy16;
yy3:
#line 221 "scanner.re"
	{
					goto echo;
				}
#line 122 "scanner.cc"
yy4:
	yych = *++YYCURSOR;
	if(yych == '/') goto yy10;
	goto yy3;
yy5:
	++YYCURSOR;
#line 197 "scanner.re"
	{
					if (ignore_eoc)
					{
						ignore_cnt++;
					}
					else
					{
						out.write((const char*)(tok), (const char*)(cursor) - (const char*)(tok));
					}
					tok = pos = cursor;
					cline++;
					goto echo;
				}
#line 143 "scanner.cc"
yy7:
	++YYCURSOR;
#line 210 "scanner.re"
	{
					if (!ignore_eoc)
					{
						out.write((const char*)(tok), (const char*)(cursor) - (const char*)(tok) - 1);
						// -1 so we don't write out the \0
					}
					if(cursor == eof)
					{
						RETURN(0);
					}
				}
#line 158 "scanner.cc"
yy9:
	yych = *++YYCURSOR;
	goto yy3;
yy10:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych == 0x0A) goto yy14;
	if(yych == 0x0D) goto yy12;
yy11:
#line 180 "scanner.re"
	{
					if (ignore_eoc)
					{
						if (ignore_cnt)
						{
							out << "\n" << sourceFileInfo;
						}
						ignore_eoc = false;
						ignore_cnt = 0;
					}
					else
					{
						out.write((const char*)(tok), (const char*)(cursor) - (const char*)(tok));
					}
					tok = pos = cursor;
					goto echo;
				}
#line 186 "scanner.cc"
yy12:
	yych = *++YYCURSOR;
	if(yych == 0x0A) goto yy14;
yy13:
	YYCURSOR = YYMARKER;
	if(yyaccept <= 0) {
		goto yy3;
	} else {
		goto yy11;
	}
yy14:
	++YYCURSOR;
#line 162 "scanner.re"
	{
					cline++;
					if (ignore_eoc)
					{
						if (ignore_cnt)
						{
							out << sourceFileInfo;
						}
						ignore_eoc = false;
						ignore_cnt = 0;
					}
					else
					{
						out.write((const char*)(tok), (const char*)(cursor) - (const char*)(tok));
					}
					tok = pos = cursor;
					goto echo;
				}
#line 218 "scanner.cc"
yy16:
	yych = *++YYCURSOR;
	if(yych != '!') goto yy13;
	yych = *++YYCURSOR;
	switch(yych) {
	case 'g':	goto yy20;
	case 'i':	goto yy19;
	case 'm':	goto yy21;
	case 'r':	goto yy22;
	case 't':	goto yy18;
	default:	goto yy13;
	}
yy18:
	yych = *++YYCURSOR;
	if(yych == 'y') goto yy59;
	goto yy13;
yy19:
	yych = *++YYCURSOR;
	if(yych == 'g') goto yy48;
	goto yy13;
yy20:
	yych = *++YYCURSOR;
	if(yych == 'e') goto yy35;
	goto yy13;
yy21:
	yych = *++YYCURSOR;
	if(yych == 'a') goto yy27;
	goto yy13;
yy22:
	yych = *++YYCURSOR;
	if(yych != 'e') goto yy13;
	yych = *++YYCURSOR;
	if(yych != '2') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 'c') goto yy13;
	++YYCURSOR;
#line 114 "scanner.re"
	{
					if (bUsedYYMaxFill && bSinglePass)
					{
						fatal("found scanner block after YYMAXFILL declaration");
					}
					out.write((const char*)(tok), (const char*)(&cursor[-7]) - (const char*)(tok));
					tok = cursor;
					RETURN(1);
				}
#line 265 "scanner.cc"
yy27:
	yych = *++YYCURSOR;
	if(yych != 'x') goto yy13;
	yych = *++YYCURSOR;
	if(yych != ':') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 'r') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 'e') goto yy13;
	yych = *++YYCURSOR;
	if(yych != '2') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 'c') goto yy13;
	++YYCURSOR;
#line 123 "scanner.re"
	{
					if (bUsedYYMaxFill)
					{
						fatal("cannot generate YYMAXFILL twice");
					}
					out << "#define YYMAXFILL " << maxFill << std::endl;
					tok = pos = cursor;
					ignore_eoc = true;
					bUsedYYMaxFill = true;
					goto echo;
				}
#line 292 "scanner.cc"
yy35:
	yych = *++YYCURSOR;
	if(yych != 't') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 's') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 't') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 'a') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 't') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 'e') goto yy13;
	yych = *++YYCURSOR;
	if(yych != ':') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 'r') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 'e') goto yy13;
	yych = *++YYCURSOR;
	if(yych != '2') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 'c') goto yy13;
	++YYCURSOR;
#line 134 "scanner.re"
	{
					tok = pos = cursor;
					genGetState(out, topIndent, 0);
					ignore_eoc = true;
					goto echo;
				}
#line 324 "scanner.cc"
yy48:
	yych = *++YYCURSOR;
	if(yych != 'n') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 'o') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 'r') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 'e') goto yy13;
	yych = *++YYCURSOR;
	if(yych != ':') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 'r') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 'e') goto yy13;
	yych = *++YYCURSOR;
	if(yych != '2') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 'c') goto yy13;
	++YYCURSOR;
#line 140 "scanner.re"
	{
					tok = pos = cursor;
					ignore_eoc = true;
					goto echo;
				}
#line 351 "scanner.cc"
yy59:
	yych = *++YYCURSOR;
	if(yych != 'p') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 'e') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 's') goto yy13;
	yych = *++YYCURSOR;
	if(yych != ':') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 'r') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 'e') goto yy13;
	yych = *++YYCURSOR;
	if(yych != '2') goto yy13;
	yych = *++YYCURSOR;
	if(yych != 'c') goto yy13;
	++YYCURSOR;
#line 145 "scanner.re"
	{
					if (bSinglePass)
					{
						fatal("cannot generate types inline in single pass mode");
					}
					tok = pos = cursor;
					ignore_eoc = true;
					if (bLastPass)
					{
						out << outputFileInfo;
						out << "\n";
						out << typesInline;
						out << "\n";
						out << sourceFileInfo;
					}
					goto echo;
				}
#line 388 "scanner.cc"
}
#line 224 "scanner.re"

}


int Scanner::scan()
{
	char *cursor = cur;
	uint depth;

scan:
	tchar = cursor - pos;
	tline = cline;
	tok = cursor;
	if (iscfg == 1)
	{
		goto config;
	}
	else if (iscfg == 2)
	{
		goto value;
	}

#line 413 "scanner.cc"
{
	YYCTYPE yych;
	unsigned int yyaccept = 0;
	static const unsigned char yybm[] = {
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 122,   8, 112, 112, 120, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		122, 112,  48, 112, 112, 112, 112,  80, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		244, 244, 244, 244, 244, 244, 244, 244, 
		244, 244, 112, 112, 112, 112, 112, 112, 
		112, 116, 116, 116, 116, 116, 116, 116, 
		116, 116, 116, 116, 116, 116, 116, 116, 
		116, 116, 116, 116, 116, 116, 116, 116, 
		116, 116, 116, 112,   0,  96, 112, 116, 
		112, 116, 116, 116, 116, 116, 116, 116, 
		116, 116, 116, 116, 116, 116, 116, 116, 
		116, 116, 116, 116, 116, 116, 116, 116, 
		116, 116, 116, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
	};
	if((YYLIMIT - YYCURSOR) < 5) YYFILL(5);
	yych = *YYCURSOR;
	if(yych <= '/') {
		if(yych <= '"') {
			if(yych <= 0x0C) {
				if(yych <= 0x08) goto yy98;
				if(yych <= 0x09) goto yy92;
				if(yych <= 0x0A) goto yy94;
				goto yy98;
			} else {
				if(yych <= 0x1F) {
					if(yych <= 0x0D) goto yy96;
					goto yy98;
				} else {
					if(yych <= ' ') goto yy92;
					if(yych <= '!') goto yy98;
					goto yy77;
				}
			}
		} else {
			if(yych <= '*') {
				if(yych <= '&') goto yy98;
				if(yych <= '\'') goto yy79;
				if(yych <= ')') goto yy84;
				goto yy75;
			} else {
				if(yych <= ',') {
					if(yych <= '+') goto yy85;
					goto yy84;
				} else {
					if(yych <= '-') goto yy98;
					if(yych <= '.') goto yy90;
					goto yy73;
				}
			}
		}
	} else {
		if(yych <= '\\') {
			if(yych <= '>') {
				if(yych <= ':') goto yy98;
				if(yych == '<') goto yy83;
				goto yy84;
			} else {
				if(yych <= '@') {
					if(yych <= '?') goto yy85;
					goto yy98;
				} else {
					if(yych <= 'Z') goto yy89;
					if(yych <= '[') goto yy81;
					goto yy84;
				}
			}
		} else {
			if(yych <= 'q') {
				if(yych == '_') goto yy89;
				if(yych <= '`') goto yy98;
				goto yy89;
			} else {
				if(yych <= 'z') {
					if(yych <= 'r') goto yy87;
					goto yy89;
				} else {
					if(yych <= '{') goto yy71;
					if(yych <= '|') goto yy84;
					goto yy98;
				}
			}
		}
	}
yy71:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych <= '/') {
		if(yych == ',') goto yy147;
	} else {
		if(yych <= '0') goto yy144;
		if(yych <= '9') goto yy145;
	}
yy72:
#line 246 "scanner.re"
	{
					depth = 1;
					goto code;
				}
#line 535 "scanner.cc"
yy73:
	++YYCURSOR;
	if((yych = *YYCURSOR) == '*') goto yy142;
yy74:
#line 299 "scanner.re"
	{
					RETURN(*tok);
				}
#line 544 "scanner.cc"
yy75:
	++YYCURSOR;
	if((yych = *YYCURSOR) == '/') goto yy140;
#line 303 "scanner.re"
	{
					yylval.op = *tok;
					RETURN(STAR);
				}
#line 553 "scanner.cc"
yy77:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych != 0x0A) goto yy136;
yy78:
#line 273 "scanner.re"
	{
					fatal("unterminated string constant (missing \")");
				}
#line 563 "scanner.cc"
yy79:
	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych != 0x0A) goto yy131;
yy80:
#line 276 "scanner.re"
	{
					fatal("unterminated string constant (missing ')");
				}
#line 573 "scanner.cc"
yy81:
	yyaccept = 3;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych == 0x0A) goto yy82;
	if(yych == '^') goto yy122;
	goto yy121;
yy82:
#line 292 "scanner.re"
	{
					fatal("unterminated range (missing ])");
				}
#line 585 "scanner.cc"
yy83:
	yyaccept = 4;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych == '>') goto yy115;
	goto yy74;
yy84:
	yych = *++YYCURSOR;
	goto yy74;
yy85:
	++YYCURSOR;
#line 307 "scanner.re"
	{
					yylval.op = *tok;
					RETURN(CLOSE);
				}
#line 601 "scanner.cc"
yy87:
	++YYCURSOR;
	if((yych = *YYCURSOR) == 'e') goto yy104;
	goto yy103;
yy88:
#line 347 "scanner.re"
	{
					cur = cursor;
					yylval.symbol = Symbol::find(token());
					return ID;
				}
#line 613 "scanner.cc"
yy89:
	yych = *++YYCURSOR;
	goto yy103;
yy90:
	++YYCURSOR;
#line 353 "scanner.re"
	{
					cur = cursor;
					yylval.regexp = mkDot();
					return RANGE;
				}
#line 625 "scanner.cc"
yy92:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy101;
yy93:
#line 359 "scanner.re"
	{
					goto scan;
				}
#line 635 "scanner.cc"
yy94:
	++YYCURSOR;
yy95:
#line 363 "scanner.re"
	{
					if(cursor == eof) RETURN(0);
					pos = cursor;
					cline++;
					goto scan;
				}
#line 646 "scanner.cc"
yy96:
	++YYCURSOR;
	if((yych = *YYCURSOR) == 0x0A) goto yy99;
yy97:
#line 370 "scanner.re"
	{
					std::ostringstream msg;
					msg << "unexpected character: ";
					prtChOrHex(msg, *tok);
					fatal(msg.str().c_str());
					goto scan;
				}
#line 659 "scanner.cc"
yy98:
	yych = *++YYCURSOR;
	goto yy97;
yy99:
	yych = *++YYCURSOR;
	goto yy95;
yy100:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy101:
	if(yybm[0+yych] & 2) {
		goto yy100;
	}
	goto yy93;
yy102:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy103:
	if(yybm[0+yych] & 4) {
		goto yy102;
	}
	goto yy88;
yy104:
	yych = *++YYCURSOR;
	if(yych != '2') goto yy103;
	yych = *++YYCURSOR;
	if(yych != 'c') goto yy103;
	yyaccept = 5;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych != ':') goto yy103;
yy107:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= '^') {
		if(yych <= '@') goto yy108;
		if(yych <= 'Z') goto yy109;
	} else {
		if(yych == '`') goto yy108;
		if(yych <= 'z') goto yy109;
	}
yy108:
	YYCURSOR = YYMARKER;
	if(yyaccept <= 3) {
		if(yyaccept <= 1) {
			if(yyaccept <= 0) {
				goto yy72;
			} else {
				goto yy78;
			}
		} else {
			if(yyaccept <= 2) {
				goto yy80;
			} else {
				goto yy82;
			}
		}
	} else {
		if(yyaccept <= 5) {
			if(yyaccept <= 4) {
				goto yy74;
			} else {
				goto yy88;
			}
		} else {
			if(yyaccept <= 6) {
				goto yy111;
			} else {
				goto yy148;
			}
		}
	}
yy109:
	yyaccept = 6;
	YYMARKER = ++YYCURSOR;
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if(yych <= '@') {
		if(yych <= '9') {
			if(yych >= '0') goto yy109;
		} else {
			if(yych <= ':') goto yy107;
			if(yych >= '@') goto yy112;
		}
	} else {
		if(yych <= '_') {
			if(yych <= 'Z') goto yy109;
			if(yych >= '_') goto yy109;
		} else {
			if(yych <= '`') goto yy111;
			if(yych <= 'z') goto yy109;
		}
	}
yy111:
#line 339 "scanner.re"
	{
					cur = cursor;
					tok+= 5; /* skip "re2c:" */
					iscfg = 1;
					yylval.str = new Str(token());
					return CONFIG;
				}
#line 764 "scanner.cc"
yy112:
	yych = *++YYCURSOR;
	if(yych <= '^') {
		if(yych <= '@') goto yy108;
		if(yych >= '[') goto yy108;
	} else {
		if(yych == '`') goto yy108;
		if(yych >= '{') goto yy108;
	}
yy113:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= 'Z') {
		if(yych <= '/') goto yy111;
		if(yych <= '9') goto yy113;
		if(yych <= '@') goto yy111;
		goto yy113;
	} else {
		if(yych <= '_') {
			if(yych <= '^') goto yy111;
			goto yy113;
		} else {
			if(yych <= '`') goto yy111;
			if(yych <= 'z') goto yy113;
			goto yy111;
		}
	}
yy115:
	YYCTXMARKER = YYCURSOR + 1;
	yych = *++YYCURSOR;
	goto yy117;
yy116:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy117:
	if(yybm[0+yych] & 8) {
		goto yy116;
	}
	if(yych != '{') goto yy108;
	++YYCURSOR;
	YYCURSOR = YYCTXMARKER;
#line 296 "scanner.re"
	{
					RETURN(NOCOND);
				}
#line 812 "scanner.cc"
yy120:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy121:
	if(yybm[0+yych] & 16) {
		goto yy120;
	}
	if(yych <= '[') goto yy108;
	if(yych <= '\\') goto yy124;
	goto yy125;
yy122:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= '[') {
		if(yych == 0x0A) goto yy108;
		goto yy122;
	} else {
		if(yych <= '\\') goto yy127;
		if(yych <= ']') goto yy128;
		goto yy122;
	}
yy124:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych == 0x0A) goto yy108;
	goto yy120;
yy125:
	++YYCURSOR;
#line 286 "scanner.re"
	{
					cur = cursor;
					yylval.regexp = ranToRE(token());
					return RANGE;
				}
#line 850 "scanner.cc"
yy127:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych == 0x0A) goto yy108;
	goto yy122;
yy128:
	++YYCURSOR;
#line 280 "scanner.re"
	{
					cur = cursor;
					yylval.regexp = invToRE(token());
					return RANGE;
				}
#line 865 "scanner.cc"
yy130:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy131:
	if(yybm[0+yych] & 32) {
		goto yy130;
	}
	if(yych <= '&') goto yy108;
	if(yych <= '\'') goto yy133;
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych == 0x0A) goto yy108;
	goto yy130;
yy133:
	++YYCURSOR;
#line 267 "scanner.re"
	{
					cur = cursor;
					yylval.regexp = strToCaseInsensitiveRE(token());
					return STRING;
				}
#line 889 "scanner.cc"
yy135:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy136:
	if(yybm[0+yych] & 64) {
		goto yy135;
	}
	if(yych <= '!') goto yy108;
	if(yych <= '"') goto yy138;
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych == 0x0A) goto yy108;
	goto yy135;
yy138:
	++YYCURSOR;
#line 261 "scanner.re"
	{
					cur = cursor;
					yylval.regexp = strToRE(token());
					return STRING;
				}
#line 913 "scanner.cc"
yy140:
	++YYCURSOR;
#line 256 "scanner.re"
	{
					tok = cursor;
					RETURN(0);
				}
#line 921 "scanner.cc"
yy142:
	++YYCURSOR;
#line 251 "scanner.re"
	{
					depth = 1;
					goto comment;
				}
#line 929 "scanner.cc"
yy144:
	yych = *++YYCURSOR;
	if(yych == ',') goto yy158;
	goto yy146;
yy145:
	++YYCURSOR;
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
yy146:
	if(yybm[0+yych] & 128) {
		goto yy145;
	}
	if(yych == ',') goto yy151;
	if(yych == '}') goto yy149;
	goto yy108;
yy147:
	++YYCURSOR;
yy148:
#line 335 "scanner.re"
	{
					fatal("illegal closure form, use '{n}', '{n,}', '{n,m}' where n and m are numbers");
				}
#line 952 "scanner.cc"
yy149:
	++YYCURSOR;
#line 317 "scanner.re"
	{
					yylval.extop.minsize = atoi((char *)tok+1);
					yylval.extop.maxsize = atoi((char *)tok+1);
					RETURN(CLOSESIZE);
				}
#line 961 "scanner.cc"
yy151:
	yyaccept = 7;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych <= '/') goto yy148;
	if(yych <= '9') goto yy154;
	if(yych != '}') goto yy148;
	++YYCURSOR;
#line 329 "scanner.re"
	{
					yylval.extop.minsize = atoi((char *)tok+1);
					yylval.extop.maxsize = -1;
					RETURN(CLOSESIZE);
				}
#line 975 "scanner.cc"
yy154:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= '/') goto yy108;
	if(yych <= '9') goto yy154;
	if(yych != '}') goto yy108;
	++YYCURSOR;
#line 323 "scanner.re"
	{
					yylval.extop.minsize = atoi((char *)tok+1);
					yylval.extop.maxsize = MAX(yylval.extop.minsize,atoi(strchr((char *)tok, ',')+1));
					RETURN(CLOSESIZE);
				}
#line 990 "scanner.cc"
yy158:
	yyaccept = 7;
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych <= '/') goto yy148;
	if(yych <= '9') goto yy154;
	if(yych != '}') goto yy148;
	++YYCURSOR;
#line 312 "scanner.re"
	{
					yylval.op = '*';
					RETURN(CLOSE);
				}
#line 1003 "scanner.cc"
}
#line 377 "scanner.re"


code:

#line 1010 "scanner.cc"
{
	YYCTYPE yych;
	static const unsigned char yybm[] = {
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192,   0, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192,  64, 192, 192, 192, 192, 128, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192,   0, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
	};
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if(yych <= '&') {
		if(yych <= 0x0A) {
			if(yych <= 0x00) goto yy169;
			if(yych <= 0x09) goto yy171;
			goto yy167;
		} else {
			if(yych == '"') goto yy173;
			goto yy171;
		}
	} else {
		if(yych <= '{') {
			if(yych <= '\'') goto yy174;
			if(yych <= 'z') goto yy171;
			goto yy165;
		} else {
			if(yych != '}') goto yy171;
		}
	}
	++YYCURSOR;
#line 381 "scanner.re"
	{
					if(--depth == 0)
					{
						cur = cursor;
						yylval.token = new Token(token(), tline);
						return CODE;
					}
					goto code;
				}
#line 1078 "scanner.cc"
yy165:
	++YYCURSOR;
#line 390 "scanner.re"
	{
					++depth;
					goto code;
				}
#line 1086 "scanner.cc"
yy167:
	++YYCURSOR;
#line 394 "scanner.re"
	{
					if(cursor == eof)
					{
						fatal("missing '}'");
					}
					pos = cursor;
					cline++;
					goto code;
				}
#line 1099 "scanner.cc"
yy169:
	++YYCURSOR;
#line 403 "scanner.re"
	{
					if(cursor == eof)
					{
						if (depth)
						{
							fatal("missing '}'");
						}
						RETURN(0);
					}
					goto code;
				}
#line 1114 "scanner.cc"
yy171:
	++YYCURSOR;
yy172:
#line 414 "scanner.re"
	{
					goto code;
				}
#line 1122 "scanner.cc"
yy173:
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych == 0x0A) goto yy172;
	goto yy180;
yy174:
	yych = *(YYMARKER = ++YYCURSOR);
	if(yych == 0x0A) goto yy172;
	goto yy176;
yy175:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy176:
	if(yybm[0+yych] & 64) {
		goto yy175;
	}
	if(yych <= '&') goto yy177;
	if(yych <= '\'') goto yy171;
	goto yy178;
yy177:
	YYCURSOR = YYMARKER;
	goto yy172;
yy178:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych == 0x0A) goto yy177;
	goto yy175;
yy179:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy180:
	if(yybm[0+yych] & 128) {
		goto yy179;
	}
	if(yych <= '!') goto yy177;
	if(yych <= '"') goto yy171;
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych == 0x0A) goto yy177;
	goto yy179;
}
#line 417 "scanner.re"


comment:

#line 1172 "scanner.cc"
{
	YYCTYPE yych;
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if(yych <= ')') {
		if(yych == 0x0A) goto yy187;
		goto yy189;
	} else {
		if(yych <= '*') goto yy184;
		if(yych == '/') goto yy186;
		goto yy189;
	}
yy184:
	++YYCURSOR;
	if((yych = *YYCURSOR) == '/') goto yy192;
yy185:
#line 445 "scanner.re"
	{
					if(cursor == eof)
					{
						RETURN(0);
					}
					goto comment;
				}
#line 1197 "scanner.cc"
yy186:
	yych = *++YYCURSOR;
	if(yych == '*') goto yy190;
	goto yy185;
yy187:
	++YYCURSOR;
#line 436 "scanner.re"
	{
					if(cursor == eof)
					{
						RETURN(0);
					}
					tok = pos = cursor;
					cline++;
					goto comment;
				}
#line 1214 "scanner.cc"
yy189:
	yych = *++YYCURSOR;
	goto yy185;
yy190:
	++YYCURSOR;
#line 431 "scanner.re"
	{
					++depth;
					fatal("ambiguous /* found");
					goto comment;
				}
#line 1226 "scanner.cc"
yy192:
	++YYCURSOR;
#line 421 "scanner.re"
	{
					if(--depth == 0)
					{
						goto scan;
					}
					else
					{
						goto comment;
					}
				}
#line 1240 "scanner.cc"
}
#line 452 "scanner.re"


config:

#line 1247 "scanner.cc"
{
	YYCTYPE yych;
	static const unsigned char yybm[] = {
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0, 128,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		128,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
	};
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if(yych <= 0x1F) {
		if(yych != 0x09) goto yy200;
	} else {
		if(yych <= ' ') goto yy196;
		if(yych == '=') goto yy198;
		goto yy200;
	}
yy196:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy205;
yy197:
#line 456 "scanner.re"
	{
					goto config;
				}
#line 1302 "scanner.cc"
yy198:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy203;
yy199:
#line 459 "scanner.re"
	{
					iscfg = 2;
					cur = cursor;
					RETURN('=');
				}
#line 1314 "scanner.cc"
yy200:
	++YYCURSOR;
#line 464 "scanner.re"
	{
					fatal("missing '='");
				}
#line 1321 "scanner.cc"
yy202:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy203:
	if(yybm[0+yych] & 128) {
		goto yy202;
	}
	goto yy199;
yy204:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy205:
	if(yych == 0x09) goto yy204;
	if(yych == ' ') goto yy204;
	goto yy197;
}
#line 467 "scanner.re"


value:

#line 1345 "scanner.cc"
{
	YYCTYPE yych;
	static const unsigned char yybm[] = {
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 192,   0, 248, 248, 192, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		192, 248, 104, 248, 248, 248, 248, 152, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		252, 252, 252, 252, 252, 252, 252, 252, 
		252, 252, 248, 192, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248,   8, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
	};
	if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if(yych <= '&') {
		if(yych <= 0x0D) {
			if(yych <= 0x08) goto yy214;
			if(yych <= 0x0A) goto yy208;
			if(yych <= 0x0C) goto yy214;
		} else {
			if(yych <= ' ') {
				if(yych <= 0x1F) goto yy214;
			} else {
				if(yych == '"') goto yy216;
				goto yy214;
			}
		}
	} else {
		if(yych <= '/') {
			if(yych <= '\'') goto yy218;
			if(yych == '-') goto yy211;
			goto yy214;
		} else {
			if(yych <= '9') {
				if(yych <= '0') goto yy209;
				goto yy212;
			} else {
				if(yych != ';') goto yy214;
			}
		}
	}
yy208:
#line 477 "scanner.re"
	{
					cur = cursor;
					yylval.str = new Str(token());
					iscfg = 0;
					return VALUE;
				}
#line 1419 "scanner.cc"
yy209:
	++YYCURSOR;
	if(yybm[0+(yych = *YYCURSOR)] & 8) {
		goto yy214;
	}
yy210:
#line 471 "scanner.re"
	{
					cur = cursor;
					yylval.number = atoi(token().to_string().c_str());
					iscfg = 0;
					return NUMBER;
				}
#line 1433 "scanner.cc"
yy211:
	yych = *++YYCURSOR;
	if(yych <= '0') goto yy215;
	if(yych >= ':') goto yy215;
yy212:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yybm[0+yych] & 4) {
		goto yy212;
	}
	if(yych <= 0x0D) {
		if(yych <= 0x08) goto yy214;
		if(yych <= 0x0A) goto yy210;
		if(yych >= 0x0D) goto yy210;
	} else {
		if(yych <= ' ') {
			if(yych >= ' ') goto yy210;
		} else {
			if(yych == ';') goto yy210;
		}
	}
yy214:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy215:
	if(yybm[0+yych] & 8) {
		goto yy214;
	}
	goto yy208;
yy216:
	YYMARKER = ++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yybm[0+yych] & 16) {
		goto yy216;
	}
	if(yych <= '!') {
		if(yych == 0x0A) goto yy208;
		goto yy226;
	} else {
		if(yych <= '"') goto yy214;
		if(yych <= '[') goto yy226;
		goto yy228;
	}
yy218:
	YYMARKER = ++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yybm[0+yych] & 32) {
		goto yy218;
	}
	if(yych <= '&') {
		if(yych == 0x0A) goto yy208;
	} else {
		if(yych <= '\'') goto yy214;
		if(yych >= '\\') goto yy223;
	}
yy220:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yybm[0+yych] & 64) {
		goto yy220;
	}
	if(yych <= '&') goto yy222;
	if(yych <= '\'') goto yy224;
	goto yy225;
yy222:
	YYCURSOR = YYMARKER;
	goto yy208;
yy223:
	YYMARKER = ++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= 0x0D) {
		if(yych <= 0x09) {
			if(yych <= 0x08) goto yy218;
			goto yy220;
		} else {
			if(yych <= 0x0A) goto yy208;
			if(yych <= 0x0C) goto yy218;
			goto yy220;
		}
	} else {
		if(yych <= ' ') {
			if(yych <= 0x1F) goto yy218;
			goto yy220;
		} else {
			if(yych == ';') goto yy220;
			goto yy218;
		}
	}
yy224:
	yych = *++YYCURSOR;
	goto yy208;
yy225:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych == 0x0A) goto yy222;
	goto yy220;
yy226:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yybm[0+yych] & 128) {
		goto yy226;
	}
	if(yych <= '!') goto yy222;
	if(yych <= '"') goto yy224;
	goto yy229;
yy228:
	YYMARKER = ++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych <= 0x0D) {
		if(yych <= 0x09) {
			if(yych <= 0x08) goto yy216;
			goto yy226;
		} else {
			if(yych <= 0x0A) goto yy208;
			if(yych <= 0x0C) goto yy216;
			goto yy226;
		}
	} else {
		if(yych <= ' ') {
			if(yych <= 0x1F) goto yy216;
			goto yy226;
		} else {
			if(yych == ';') goto yy226;
			goto yy216;
		}
	}
yy229:
	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if(yych == 0x0A) goto yy222;
	goto yy226;
}
#line 483 "scanner.re"

}

void Scanner::fatal(uint ofs, const char *msg) const
{
	out.flush();
	std::cerr << "re2c: error: "
		<< "line " << tline << ", column " << (tchar + ofs + 1) << ": "
		<< msg << std::endl;
	exit(1);
}

void Scanner::fatalf(const char *fmt, ...) const
{
	char szBuf[4096];

	va_list args;
	
	va_start(args, fmt);
	vsnprintf(szBuf, sizeof(szBuf), fmt, args);
	va_end(args);
	
	szBuf[sizeof(szBuf)-1] = '0';
	
	fatal(szBuf);
}

Scanner::~Scanner()
{
	if (bot)
	{
		delete [] bot;
	}
}

} // end namespace re2c
