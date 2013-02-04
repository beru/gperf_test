%{
#include <stdio.h>


%}
struct IDPair
{
	const char* strID;
	unsigned short rowid;
};
%%
TEST_AAA,1
TEST_BBB,2
TEST_CCC,3
TEST_DDD,4
TEST_EEE,5
TEST_ZZZ,6
TEST_QQQQQQ,7
TEST_BAKERATTA,8
TEST_MEOW,9
TEST_BOO,10
TEST_MOOO,11
TEST_BOW,12
TEST_SPAGHETTI,13
TEST_PASTA,14
TEST_UDON,15
TEST_SOBA,16
TEST_RAHMEN,17
TEST_SOUMEN,18
TEST_TANMEN,19
TEST_REIMEN,20
TEST_NOODLE,21
%%
int main(int argc, char* argv[])
{
	size_t i;
	size_t len;
	const struct IDPair* s;
	static const size_t ARRLEN = sizeof(wordlist) / sizeof(wordlist[0]);
	for (i=0; i<ARRLEN; ++i) {
		const struct IDPair* word = &wordlist[i];
		len = strlen(word->strID);
		if (!len) {
			continue;
		}
		s = in_word_set(word->strID, len);
		printf("%s %d \n", word->strID, s->rowid);
	}
	getchar();
	return 0;
}
