import java.util.*;
class pagereplacement
{
public static void main(String args[])
{
Scanner sc = new Scanner(System.in);
System.out.println("Enter your choice:");
System.out.println("1.FIFO");
System.out.println("2.LRU");
System.out.println("3.OPTIMAL");
int c=sc.nextInt();
switch(c)
{
case 1:
{
 int num, n, i;
System.out.print("Enter no of page frames: ");
num = sc.nextInt();
int frame[] = new int[num];
for(i = 0; i < num; i++)
 frame[i] = -1;
System.out.print("Enter total no of pages in page reference string: ");
n = sc.nextInt();
int page_stream[] = new int[n];
System.out.println("Enter page reference string:");
for(i = 0; i < n; i++)
page_stream[i] = sc.nextInt();
char check = 'F';
int j = 0, k, c1 = 0, c2 = 0;
System.out.println("\npage reference string");
for(i = 0; i < n; i++)
{
 for(k = 0; k < num; k++)
{
 if(frame[k] == page_stream[i])
 {
 check = 'H';
 c2++;
 }
}
if(j < num && check != 'H')
{
frame[j] = page_stream[i];
j++;
c1++;
}
else if(j >= num && check != 'H')
{
 j = 0;
 frame[j] = page_stream[i];
 j++;
 c1++;
}
System.out.print(page_stream[i]+"\t\t\t");
for(k = 0; k < num; k++)
{
 if(frame[k] != -1)
 System.out.print(frame[k]+"\t");
else
 System.out.print("\t");
}
System.out.println(check);
check = 'F';
}
float hitr, misr;
hitr = (float)(c2)/(float)(n);
misr = (float)(c1)/(float)(n);
System.out.println("\n\nNo. of page hits = "+c2);
System.out.println("No. of page faults = "+c1);
System.out.println("Hit ratio = "+hitr);
System.out.println("Miss ratio = "+misr);
break;
}
case 2:
{
    int num, n, i;
    System.out.print("Enter no of page frames: ");
    num = sc.nextInt();
    int frame[] = new int[num];
    int flag[] = new int[num];
    for(i = 0; i < num; i++)
    {
     frame[i] = -1;
     flag[i] = 0;
    }
    System.out.print("Enter total no of pages in page reference string: ");
    n = sc.nextInt();
    int page_stream[] = new int[n];
    System.out.println("Enter page reference string:");
    for(i = 0; i < n; i++)
    page_stream[i] = sc.nextInt();
    char check = 'F';
    int j = 0, k, c1 = 0, c2 = 0, min, lru = 0, d = 0;
    System.out.println("\n");
    System.out.println("page reference string");
    for(i = 0; i < n; i++)
    {
     min = 1000;
     for(k = 0; k < num; k++)
     {
     if(flag[k] < min)
     {
     min = flag[k];
     lru = k;
     }
     }
     for(k = 0; k < num; k++)
    {
     if(frame[k] == page_stream[i])
     {
     check = 'H';
     c++;
     flag[k] = d;
     c2++;
     }
    }
    if(j < num && check != 'H')
    {
    frame[j] = page_stream[i];
    j++;
    c++;
    flag[j-1] = d;
    c1++;
    }
    else if(j >= num && check != 'H')
    {
     frame[lru] = page_stream[i];
     d++;
     flag[lru] = d;
     c1++;
    }
    System.out.print(page_stream[i] + "\t\t");
    for(k = 0; k < num; k++)
    {
     if(frame[k] != -1)
     System.out.print(frame[k]+"\t");
    else
     System.out.print("\t");
    }
    System.out.println(check);
    check = 'F';
    }
    float hitr, misr;
    hitr = (float)(c2)/(float)(n);
    misr = (float)(c1)/(float)(n);
    System.out.println("\n\nNo. of page hits = "+c2);
    System.out.println("No. of page faults = "+c1);
    System.out.println("Hit ratio = "+hitr);
    System.out.println("Miss ratio = "+misr);
    break;
}
case 3:
{
    int num, n, i;
        System.out.print("Enter no of page frames: ");
        num = sc.nextInt();
        int frame[] = new int[num];
        for (i = 0; i < num; i++)
            frame[i] = -1;
        System.out.print("Enter total no of pages in page reference string: ");
        n = sc.nextInt();
        int page_stream[] = new int[n];
        System.out.println("Enter page reference string:");
        for (i = 0; i < n; i++)
            page_stream[i] = sc.nextInt();
        int c1 = 0, c2 = 0;
        System.out.println("\npage reference string");
        for (i = 0; i < n; i++) {
            boolean flag = false;
            for (int j = 0; j < num; j++) {
                if (frame[j] == page_stream[i]) {
                    flag = true;
                    c2++;
                    break;
                }
            }
            if (!flag) {
                int index = -1, farthest = 0;
                for (int j = 0; j < num; j++) {
                    int nextOccurrence = -1;
                    for (int k = i + 1; k < n; k++) {
                        if (frame[j] == page_stream[k]) {
                            nextOccurrence = k;
                            break;
                        }
                    }
                    if (nextOccurrence == -1) {
                        index = j;
                        break;
                    }
                    if (nextOccurrence > farthest) {
                        farthest = nextOccurrence;
                        index = j;
                    }
                }
                frame[index] = page_stream[i];
                c1++;
            }
            System.out.print(page_stream[i] + "\t\t\t");
            for (int j = 0; j < num; j++) {
                if (frame[j] != -1)
                    System.out.print(frame[j] + "\t");
                else
                    System.out.print("\t");
            }
            System.out.println(flag ? "H" : "F");
        }
        float hitr, misr;
        hitr = (float) (c2) / (float) (n);
        misr = (float) (c1) / (float) (n);
        System.out.println("\n\nNo. of page hits = " + c2);
        System.out.println("No. of page faults = " + c1);
        System.out.println("Hit ratio = " + hitr);
        System.out.println("Miss ratio = " + misr);
break;
}
default: System.out.println("wrong choice");
}
}
}