#include<stdio.h>
int m,n;

void swap(float * a,float * b)
{
  float t;
  t=*a;
  *a=*b;
  *b=t;
  return;
  }
  
  void print_mat(float a[100][100])
  {
   int i,j;
    for (i=0;i<m;i++)
   {
   for(j=0;j<n;j++)
   {
     printf("%f  ",a[i][j]);
    }
     printf("\n");}
     }
  
 void column_ch(float a[100][100],int p,int q)
 {
 int i;
 for (i=0;i<m;i++)
 {
   swap (&a[p][i],&a[q][i]);
   }
   return;
   }
   
   
  void div_row(float *a,float f)
  {
   int i;
   for(i=0;i<n;i++)
   {
    a[i]=a[i]/f;
    }
    return;
    }
   
void row_change(float * a,float * b)
  {
  int i;
    for (i=0;i<n;i++)
    {
      swap (&a[i],&b[i]);
      }
      return;}
      
        void row_trans(float * a,float *b,float f)
  {int i;
   for (i=0;i<n;i++)
   {
     a[i]=a[i]+f*b[i];
     }
     return;
   }

   int lesser(int a,int b)
   {
   if (a<=b)
   return a;
   else 
   return b;
   }
   
   
  
  main ()
  {
  int i,j,k,flag=0;
   printf("type the number of eqns and that of variables\n");
   scanf("%d %d",&m,&n);
   n=n+1;
   float a[100][100];
   printf("now enter the coefficients of x1,x2..... succesively followed by the constant on the r.h.s\n");
   for (i=0;i<m;i++)
   {
   for(j=0;j<n;j++)
   {
     scanf("%f",&a[i][j]);
   }
   }
     print_mat(a);
     for (i=0;i<lesser(m,n);i++)
     {
        if (a[i][i]==0)
        {
          for (j=i;j<m;j++)
          {
            if (a[j][i] !=0)
            {
               row_change(a[i],a[j]);
               break;
            }
          }
          if (a[i][i] == 0)
          {
            for (j=i;j<n-1;j++)
            {
              if(a[i][j] !=0)
              {
                div_row(a[i],a[i][j]);
                for (k=0;k<m;k++)
                { if (k !=i){
                   row_trans(a[k],a[i],-a[k][j]);}
                 }
                 break;
              }
            }
          }
            
        }
        else
        {
             div_row(a[i],a[i][i]);
          for (j=0;j<m;j++)
          { if (j !=i){
            row_trans(a[j],a[i],-a[j][i]);}
          }
         }  
     }
     printf("THE SOLUTION MATRIX FORM  OF GIVEN MATRIX IS\n");
          print_mat(a);
     float pivot[100];
     for (i=0,j=0;i<n-1;i++)
     {
       if (a[i][i]==0)
       {
         if (a[i][n-1]==0)
         {
         pivot[j]=i;
         j=j+1;
         flag=1;
         }
         else
         {flag=-1;
         break;}
       }
     }
     if (flag==0)
     {
       for (i=0;i<n-1;i++)
       {
         printf("x%d=%f\n",i+1,a[i][n-1]);
       }
     }
     else if(flag==-1)
     {
       printf("solution doesn't exist\n");
     }       
}
