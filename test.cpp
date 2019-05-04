#include "pch.h"
#include "../PIAA_Lab5/KMP.cpp"
#include "../PIAA_Lab5/prefix.cpp"
TEST(KMPTest, ShortString) {
	ASSERT_EQ("0,2",
		  KMP("ab", "abab"));
	ASSERT_EQ("0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26",
		  KMP("a", "aaaaaaaaaaaaaaaaaaaaaaaaaaa"));
	ASSERT_EQ("-1",
		  KMP("bb", "abababaaaaabababaaaaababaaaa"));
	ASSERT_EQ("7,16,30,49", 
		  KMP("bbaba", "abaababbbabababbbbabababbbabbabbabaabaababbaaaabbbbababaabb"));
}

TEST(KMPTest, LongString) {
	ASSERT_EQ("-1",
		  KMP("bcccaabca", "aaabbbccbbbaabacbbbacbbbaaccabcbabacacaababccbacacbacacacacaaccbbbaabcbbbbbbbcbbaabbabcbcccacabcabcbbccbccbcacbbacaacbaacbcabbabbabbbbaabbaabbccaaccbaaabbbcabbbbaaccccababbcacbbccbbacbbccbbbbacacaabcaacbacacccacbbcabcbcbccbacbbbbbaaacbccccaababbabbacc"));
	ASSERT_EQ("0,6,12,18,24,30,36,42,48,54,60,66,72,78,84,90,96,102,108,114,120,126,132,138,144,150,156,162,168,174,180,186,192,198,204,210",
		  KMP("123321", "123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321"));
	ASSERT_EQ("-1",
		  KMP("asdsdf", "asdasdasdfasdfdaffdasfafdasfdsdfasfdasdfasfdasfdasfasfdasdfasfdasfdffsdfasdfasdfasdfasfdasfdfasdfasdffdfsdafsdfasdfasfdafsdfsdfsgdsdfsdgafsdgasfdgasfdsfdagfsdagsdfasgdfasgdfsdgsfdfgasdafsgdasfdasgdfasgfdagsdfasgdfagsdfagsdfagsdafgsdasfdagsfdagsdfasdgasdfagsdafsgdafsdagfda"));
	ASSERT_EQ("41,111,128,132,162,170,195,203,207,211,215,224,249,253,303,345",
		KMP("1234", "1287641321432964053832113241836593487533412347890412938041312390874543578923490534631927431242341028973467028341234127083412378412341234670128345160845304178513241234231412346043563407513242331431234231412341234123412341233412341324608534876340953241234123412783532897504604596345034987675034850321042341234187034575893459247328472346132874612931234"));
}

TEST(KMPTest, WrongTest) {
	ASSERT_EQ("12,45,67,120,124",
		KMP("bcccaabca", "aaabbbccbbbaabacbbbacbbbaaccabcbabacacaababccbacacbacacacacaaccbbbaabcbbbbbbbcbbaabbabcbcccacabcabcbbccbccbcacbbacaacbaacbcabbabbabbbbaabbaabbccaaccbaaabbbcabbbbaaccccababbcacbbccbbacbbccbbbbacacaabcaacbacacccacbbcabcbcbccbacbbbbbaaacbccccaababbabbacc"));
	ASSERT_EQ("0,6,12,18,24,30,36,42,48,54,60,66,72,78,120,126,132,138,144,150,168,174,180,186,192,198,204,210",
		KMP("123321", "123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321123321"));
	ASSERT_EQ(",,,,,,,,,,,,,,,,",
		KMP("asdsdf", "asdasdasdfasdfdaffdasfafdasfdsdfasfdasdfasfdasfdasfasfdasdfasfdasfdffsdfasdfasdfasdfasfdasfdfasdfasdffdfsdafsdfasdfasfdafsdfsdfsgdsdfsdgafsdgasfdgasfdsfdagfsdagsdfasgdfasgdfsdgsfdfgasdafsgdasfdasgdfasgfdagsdfasgdfagsdfagsdfagsdafgsdasfdagsfdagsdfasdgasdfagsdafsgdafsdagfda"));
	ASSERT_EQ("ERROR",
		KMP("1234", "1287641321432964053832113241836593487533412347890412938041312390874543578923490534631927431242341028973467028341234127083412378412341234670128345160845304178513241234231412346043563407513242331431234231412341234123412341233412341324608534876340953241234123412783532897504604596345034987675034850321042341234187034575893459247328472346132874612931234"));
}