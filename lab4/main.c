#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>

#define endl printf("\n")

struct pair {
	char ch[5];
	char eq[10];
};
struct pair mass[137] = {
	{"A", "[.-]"}, {"a", "[.-]"}, {"А", "[.-]"}, {"а", "[.-]"},
	{"B", "[-...]"}, {"b", "[-...]"}, {"Б", "[-...]"}, {"б", "[-...]"},
	{"W", "[.--]"}, {"w", "[.--]"}, {"В", "[.--]"}, {"в", "[.--]"},
	{"G", "[--.]"}, {"g", "[--.]"}, {"Г", "[--.]"}, {"г", "[--.]"},
	{"D", "[-..]"}, {"d", "[-..]"}, {"Д", "[-..]"}, {"д", "[-..]"},
	{"E", "[.]"}, {"e", "[.]"}, {"Е", "[.]"}, {"е", "[.]"},
	{"Ё", "[.]"}, {"ё", "[.]"}, {"V", "[...-]"}, {"v", "[...-]"},
	{"Ж", "[...-]"}, {"ж", "[...-]"}, {";", "[-.--.-]"}, {"`",
								"[.----.]"},
	{"Z", "[--..]"}, {"z", "[--..]"}, {"З", "[--..]"}, {"з", "[--..]"},
	{"I", "[..]"}, {"i", "[..]"}, {"И", "[..]"}, {"и", "[..]"},
	{"J", "[.---]"}, {"j", "[.---]"}, {"Й", "[.---]"}, {"й", "[.---]"},
	{"K", "[-.-]"}, {"k", "[-.-]"}, {"К", "[-.-]"}, {"к", "[-.-]"},
	{"L", "[.-..]"}, {"l", "[.-..]"}, {"Л", "[.-..]"}, {"л", "[.-..]"},
	{"M", "[--]"}, {"m", "[--]"}, {"М", "[--]"}, {"м", "[--]"},
	{"N", "[-.]"}, {"n", "[-.]"}, {"Н", "[-.]"}, {"н", "[-.]"},
	{"O", "[---]"}, {"o", "[---]"}, {"О", "[---]"}, {"о", "[---]"},
	{"P", "[.--.]"}, {"p", "[.--.]"}, {"П", "[.--.]"}, {"п", "[.--.]"},
	{"R", "[.-.]"}, {"r", "[.-.]"}, {"Р", "[.-.]"}, {"р", "[.-.]"},
	{"S", "[...]"}, {"s", "[...]"}, {"С", "[...]"}, {"с", "[...]"},
	{"T", "[-]"}, {"t", "[-]"}, {"Т", "[-]"}, {"т", "[-]"},
	{"U", "[..-]"}, {"u", "[..-]"}, {"У", "[..-]"}, {"у", "[..-]"},
	{"F", "[..-.]"}, {"f", "[..-.]"}, {"Ф", "[..-.]"}, {"ф", "[..-.]"},
	{"H", "[....]"}, {"h", "[....]"}, {"Х", "[....]"}, {"х", "[....]"},
	{"C", "[-.-.]"}, {"c", "[-.-.]"}, {"Ц", "[-.-.]"}, {"ц", "[-.-.]"},
	{"Ч", "[---.]"}, {"ч", "[---.]"}, {"Ш", "[----]"}, {"ш", "[----]"},
	{"Q", "[--.-]"}, {"q", "[--.-]"}, {"Щ", "[--.-]"}, {"щ", "[--.-]"},
	{"Ъ", "[.--.-.]"}, {"ъ", "[.--.-.]"}, {"Y", "[-.--]"}, {"y",
								  "[-.--]"},
	{"Ы", "[-.--]"}, {"ы", "[-.--]"}, {"X", "[-..-]"}, {"x", "[-..-]"},
	{"Ь", "[-..-]"}, {"ь", "[-..-]"}, {"Э", "[...-...]"}, {"э",
								  "[...-...]"},
	{"Ю", "[..--]"}, {"ю", "[..--]"}, {"Я", "[.-.-]"}, {"я", "[.-.-]"},
	{"1", "[.----]"}, {"2", "[..--]"}, {"3", "[...--]"}, {"4", "[....-]"},
	{"5", "[.....]"}, {"6", "[-....]"}, {"7", "[--...]"}, {"8", "[---..]"},
	{"9", "[----.]"}, {"0", "[-----]"}, {".", "[.-.-.-]"}, {",",
								"[--..--]"},
	{":", "[---...]"}, {"?", "[..--..]"}, {"\'", "[.----.]"}, {"-",
								   "[-...-]"},
	{"/", "[-..-.]"}
};

int main(int argc, char *argv[])
{

	int i, j, size = 1000;
	char *temp;
	for (i = 0; i < 60; i++)
		endl;
	temp = malloc(sizeof(char) * size);
	printf("\tEnter Line in ENG or RUS...\n");
	fgets(temp, size, stdin);
	printf("\n\tYour line in Morza :\n");
	for (i = 0; i < strlen(temp) - 1; i++) {
		if (*temp == ' ')
			break;
		if (temp[i] == ' ') {
			printf("#");
			continue;
		}
		for (j = 0; j < 137; j++) {
			if (temp[i] == mass[j].ch[0]) {
				printf("%s", mass[j].eq);
				break;
			}
			/*
			   if (j == 136 && temp[i] != mass[j].ch[0])
			   printf("ErCh");
			 */
		}
	}
	printf("\n");
	free(temp);
	return 0;
}
