/* Generated by re2c */

{
	YYCTYPE yych;
	YYBACKUPTAG (yyt2);
	if (YYLESSTHAN (1)) YYFILL(1);
	yych = YYPEEK ();
	YYSKIP ();
	switch (yych) {
	case 'a':
		YYBACKUPTAG (yyt1);
		goto yy2;
	default:
		YYBACKUPTAG (yyt1);
		YYCOPYTAG (yyt2, NULL);
		goto yy2;
	}
yy2:
	YYCOPYTAG (b, yyt1);
	YYCOPYTAG (a, yyt2);
	{}
}

re2c: warning: line 3: tag 'a' is non-deterministic and induces 2 parallel instances [-Wnondeterministic-tags]
