#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main()
{
    int LS[200][200]={0}, P[200][200]={0},H[200]={1000},i,j,n,cr=0,D[200]={0},v,k,io=0,op;
    int A[200][200];
    int V[200][200];
    int L[200];
    int arc,p,min,r,in,fin,max;
    do
    {
        system("cls");
        puts("");
        puts("  ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
        puts("  บ  |1.| Determinarea Drumului Minim prin Algoritmul Belman-Kalaba         บ");
        puts("  ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน");
        puts("  บ  |2.| Determinarea Drumului Maxim prin Algoritmul Belman-Kalaba         บ");
        puts("  ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน");
        puts("  บ  |3.| Determinarea Drumului Minim/Maxim prin Algoritmul FORD            บ");
        puts("  ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน");
        puts("  บ  |0.| EXIT                                                              บ");
        puts("  ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
        printf("\nAlegeti o optiune din meniu : ");
        scanf("%d",&op);
        switch (op)
        {
            case 1:
                system("cls");
                puts("");
                puts("  ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
                puts("  บ  |1.| Determinarea Drumului Minim prin Algoritmul Belman-Kalaba         บ");
                puts("  ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
                k=1;
                printf("Introdu numarul de virfuri : "); scanf("%d",&n);
                printf("Introdu numarul de arce: "); scanf("%d",&arc);

                for(i=0;i<20;i++)
                    for(j=0;j<20;j++)
                        A[i][j]=1000;
                for(i=0;i<20;i++)
                    A[i][i]=0;

                for(k=0;k<arc;k++)
                {
                    printf("\r\nIntrodu originea->extrimitatea si ponderea\r\n");
                    printf("Originea -> "); scanf("%d",&i);
                    printf("Extrimitatea -> "); scanf("%d",&j);
                    printf("Ponderea ->"); scanf("%d",&p);
                    A[i-1][j-1]=p;

                }

                for(i=0;i<20;i++)
                    L[i]=0;



                printf("\r\n\n introdu virful initial : ");
                scanf("%d",&in);
                do
                {
                    printf("\r\n introdu virful final : ");
                    scanf("%d",&fin);
                    if (fin>n)
                    {
                        printf("\n   Ati introdus un numari mai mare de cit nr de virfuri in graful dat, nr de virfuri %d\n",n);
                    }
                }while (fin>n);
                in--;
                fin--;





                for(i=0;i<=fin;i++)
                    V[0][i]=A[i][fin];


                k=1;

                do
                {
                    cr=0;

                    for(i=0;i<=fin;i++)
                    {
                        min=1000;

                        for(j=0;j<=fin;j++)
                        {
                            if(i==j) continue;
                            if(A[i][j]+V[k-1][j]<min ) min=A[i][j]+V[k-1][j];
                        }


                        V[k][i]=min;

                    }

                    V[k][fin]=0;

                    for(i=0;i<=fin;i++)
                        if(V[k][i]!=V[k-1][i])
                        {cr=1; break;}

                    k++;


                }while(cr==1);

                k--;


                for(i=0;i<20;i++)
                    L[i]=0;



                r=0;
                i=in;
                j=0;
                L[r++]=i+1;


                for(;i!=fin;)
                {
                    if (i==j) j++;
                    if(V[k][i]-A[i][j]==V[k][j])
                    {L[r++]=j+1; i=j; j=0; }
                    else
                        j++;

                }
                L[r]=V[k][in]-V[k][fin];



                printf("\r\n Drumul este : ");

                for(i=0;L[i+1]!=0;i++)
                {
                    printf("%d",L[i]);
                    if(L[i+2]!=0) printf("->");
                }

                printf("\r\n Lungimea drumului : ");
                printf("%d",L[i]);
                printf("\r\nPentru a iesi tastati ENTER");
                getch();
                break;
            case 2:
                system("cls");
                puts("");
                puts("  ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
                puts("  บ  |2.| Determinarea Drumului Maxim prin Algoritmul Belman-Kalaba         บ");
                puts("  ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
                printf("Introdu numarul de virfuri : "); scanf("%d",&n);
                printf("Introdu numarul de arce: "); scanf("%d",&arc);

                for(i=0;i<20;i++)
                    for(j=0;j<20;j++)
                        A[i][j]=-1000;
                for(i=0;i<20;i++)
                    A[i][i]=0;

                for(k=0;k<arc;k++)
                {
                    printf("\r\nIntrodu originea->extrimitatea si ponderea\r\n");
                    printf("Originea -> "); scanf("%d",&i);
                    printf("Extrimitatea -> "); scanf("%d",&j);
                    printf("Ponderea ->"); scanf("%d",&p);
                    A[i-1][j-1]=p;

                }

                for(i=0;i<20;i++)
                    L[i]=0;



                printf("\r\n\n Introdu virful initial : ");
                scanf("%d",&in);
                do
                {
                    printf("\r\n Introdu virful final : ");
                    scanf("%d",&fin);
                    if (fin>n)
                    {
                        printf("\r\n Ati introdus un numari mai mare de cit nr de virfuri in graful dat, nr de virfuri %d\n",n);
                    }
                }while (fin>n);
                in--;
                fin--;





                for(i=0;i<=fin;i++)
                    V[0][i]=A[i][fin];


                k=1;

                do
                {
                    cr=0;

                    for(i=0;i<=fin;i++)
                    {
                        max=-1000;

                        for(j=0;j<=fin;j++)
                        {
                            if(i==j) continue;
                            if(A[i][j]+V[k-1][j]>max ) max=A[i][j]+V[k-1][j];
                        }


                        V[k][i]=max;

                    }

                    V[k][fin]=0;

                    for(i=0;i<=fin;i++)
                        if(V[k][i]!=V[k-1][i])
                        {cr=1; break;}

                    k++;


                }while(cr==1);

                k--;


                for(i=0;i<20;i++)
                    L[i]=0;



                r=0;
                i=in;
                j=0;
                L[r++]=i+1;


                for(;i!=fin;)
                {
                    if (i==j) j++;
                    if(V[k][i]-A[i][j]==V[k][j])
                    {L[r++]=j+1; i=j; j=0; }
                    else
                        j++;

                }
                L[r]=V[k][in]-V[k][fin];



                printf("\r\n Drumul este : ");

                for(i=0;L[i+1]!=0;i++)
                {
                    printf("%d",L[i]);
                    if(L[i+2]!=0) printf("->");
                }

                printf("\r\n Lungimea drumului : ");
                printf("%d",L[i]);
                printf("\r\nPentru a iesi tastati ENTER");
                getch();
                break;
            case 3:
                system("cls");
                puts("");
                puts("  ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
                puts("  บ  |3.| Determinarea Drumului Minim/Maxim prin Algoritmul Belman-Kalaba   บ");
                puts("  ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
                for(i=0;i<20;i++)
                    H[i]=1000;

                H[0]=-1; H[1]=0;


                printf("\r\nintrodu numarul de virfuri: ");
                scanf("%d",&n);

                printf("\r\n\nIntrodu LISTA DE ADIACENTA :\r\n");

                for(i=0;i<n;i++)

                {
                    printf("\r\n Virfurile adiacente lui %d \r\n",i+1);
                    LS[i][0]=1+i;
                    for(j=1;j<=n;j++)
                    {
                        scanf("%d",&LS[i][j]);
                        if(LS[i][j]==0) break;
                    }
                }


                for(i=0;i<n;i++)
                    P[i][0]=i+1;

                printf("\r\n Introdu Ponderile  \r\n");

                for(i=0;i<n;i++)
                    for(j=1;LS[i][j]!=0;j++)

                    {
                        printf("P(%d,%d)= ",LS[i][0],LS[i][j]);
                        scanf("%d",&P[i][j]);
                    }



                do
                {

                    cr=0;
                    for(i=0;i<n;i++)
                        for(j=1;j<n;j++)
                            if( (H[LS[i][j]]-H[LS[i][0]])>P[i][j] )
                            { H[LS[i][j]]=H[LS[i][0]]+P[i][j]; cr=1; }


                }while(cr!=0);




                k=0;
                v=D[k]=n;
                k++;


                for(i=n-1;i>=0;i--)
                    for(j=1;LS[i][j]!=0;j++)
                        if(LS[i][j]==v && (H[LS[i][j]]-H[LS[i][0]])==P[i][j] )
                        {
                            D[k++]=LS[i][0];
                            v=LS[i][0];
                        }

                printf("\r\n Drumule minim este : ");
                for(i=--k;i>=0;i--)
                {
                    printf("%d ", D[i]);
                }

                printf("\r\n Lungimea lui este : %d ",H[n]);


                for(i=0;i<20;i++)
                    H[i]=-1000;

                H[0]=-1; H[1]=0;


                for(i=0;i<20;i++)
                    D[i]=0;

                do
                {
                    io++;
                    cr=0;
                    for(i=0;i<n;i++)
                        for(j=1;j<n;j++)
                            if( (H[LS[i][j]]-H[LS[i][0]])<P[i][j] )
                            { H[LS[i][j]]=H[LS[i][0]]+P[i][j]; cr=1;  }


                }while(cr!=0);

                k=0;
                v=D[k]=n;
                k++;


                for(i=n-1;i>=0;i--)
                    for(j=1;LS[i][j]!=0;j++)
                        if(LS[i][j]==v && (H[LS[i][j]]-H[LS[i][0]])==P[i][j] )
                        {
                            D[k++]=LS[i][0];
                            v=LS[i][0];
                        }

                printf("\r\n\n Drumule maxim este : ");
                for(i=--k;i>=0;i--)
                {
                    printf("%d ", D[i]);
                }

                printf("\r\n Lungimea lui este : %d ",H[n]);
                printf("\r\nPentru a iesi tastati ENTER");
                getch();
                break;
        }
    }while (op!=0);
}