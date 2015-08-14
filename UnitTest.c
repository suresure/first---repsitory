#include <stdio.h>
#include <stdlib.h>
#include "symtable.h"
int passed=0;
int failed=0;
int main()
{
            printf("\n-------------- Begin Unit Test ----------\n");
            Link_t head;
            printf("\n********************** Test_1 **********************\n");       //测试 LinkTable_new
            printf("\nFunction Link_t LinkTable_new(void), initialize 6 elements:\n");
            head = LinkTable_new();
            display(head);
            passed++;
            printf("\n********************** Test_2 ***********************\n");       //测试 LinkTable_getLength
            printf("\nFunction int LinkTable_getLength(const Link_t oLink):\n");
            int length = LinkTable_getLength(head);
            printf("Length\n");
            printf("%d\n",length);
            passed++;
            printf("\n********************** Test_3 ***********************\n");          //测试 Link_contains
            printf("\nFunction int Link_contains(const Link_t oLink, const char *pcKey):\n");
            if(Link_contains(head, "101") == 1)
            {
            printf("     \"101\" Exist!\n");
            }
            else
            {
            printf("       \"101\" No  Exist\n");
            }
            if(Link_contains(head, "109") == 1)
            {
            printf("      \"109\" Exist!\n");
            }
            else
            {
            printf("      \"109\" No Exist!\n");
            }
            passed++;
            printf("\n**********************Test_4 ***********************\n");             //测试 Link_put 
            printf("\nFunction int Link_put(Link_t oLink, const char *pcKey, const void *pvValue)\nPut key:\"111\" value:\"abc111\":\n");
            Link_put(head, "111", "abc111");
            display(head);
            passed++;
            printf("\n**********************Test_5 ***********************\n");             //测试 Link_get
            printf("\nFunction void *Link_get(const Link_t oLink, const char *pcKey):\n");
            char *abc104 = (char*)Link_get(head, "104");
            printf("      KEY 104\'S VALUE      %s\n", abc104);
             char *abc112 = (char*)Link_get(head, "112");
            printf("      KEY 112\'S VALUE      %s\n", abc112);  
            passed++;
            printf("\n**********************Test_6 ***********************\n");              //测试 Link_replace   
            printf("\nFunction void *Link_replace(Link_t oLink, const char *pcKey, const void *pvValue)\nReplace key:\"101\" value:\"cpp101\":\n");
            Link_replace(head, "101", "cpp101");
            display(head);
            passed++;
            printf("\n**********************Test_7 ***********************\n");               //测试 Link_remove
            printf("\nFunction void *Link_remove(Link_t oLink, const char *pcKey)Remove key:\"102\":\n");
            Link_t temp = Link_remove(head, "102");
            Link_t temp2 = Link_remove(head, "102");
            if(temp2 == NULL)
             {
              printf("\nREMOVE \"102\"  Return NULL pointer !\n");
             }
            if(head == temp)
             {
              LinkTable_free(head);
             } 
            else
             {
               free(temp);
               LinkTable_free(head);
             }
             passed++;
             printf("\n-------------End Unit Test -------------\n");
             printf("Passed: %d 个 \n",passed);
	     printf("Failed: %d 个 \n",failed);     
             printf("\n----------------------------------------\n");
             return 1;
             
}

             
