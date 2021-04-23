#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <iterator>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <random>


using namespace std;

#define simu_num 3
#define simu_Time 1200
#define omega 100000

double rand01()  //(0,1) Uniform dist
{
	double temp;
	temp = double( rand()+0.5 ) / (double(RAND_MAX) + 1.0);
	return temp;
}


int main()
{
    int inf_num[simu_num][simu_Time];
    int node_status[omega+1];
    int infected_num ;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1,omega);

    for(int kk=0;kk<simu_num;kk++) // three times of simulations
    {

        //initilization
    for (int i=1;i< omega+1;i++)
    {
        node_status[i]=0;//immune=0
    }
    for (int j=0;j<100;j++)
    {
        for (int ii=1;ii<11;ii++)
        {
            node_status[ii+j*1000]=1;//susceptitle=1
            //cout<< node_status[ii+j*1000] <<"\n";
        }
    }

    node_status[1001] = 2 ; //infectious=2
    infected_num = 1;
    //int ip_scan_num;
    int x;

    for (int k=0; k<simu_Time;k++) //each simulation has 1200 time ticks
    {
        //ip_scan_num = infected_num * 3;
        //for (int j=0; j<ip_scan_num;j++)
        //{
                for (int j=0;j<100;j++)
             {
                 for (int ii=1;ii<11;ii++)
                {
                  if(node_status[ii+j*1000]==2) //infected=2
                  {
                       uniform_int_distribution<int> distribution2((ii+j*1000-10),(ii+j*1000+10));
                        for (int jj=0;jj<3;jj++)
                      {
                        double flip = rand01();
                        //cout<< flip <<"\n";
                        if (flip <= 0.8)
                           {
                             //x = rand()%21+(ii+j*1000 - 10);
                             x = distribution2(generator);
                           }
                        else
                           {
                             //x=rand()%omega+1;
                             x = distribution(generator);
                           }
                        if (node_status[x]==1)
                         {
                           infected_num=infected_num+1;
                           node_status[x]=2;
                           if(infected_num==1000) break;

                           }
                        }
                  }

                 }
             }


       // }
        inf_num[kk][k] = infected_num;
        //cout<<inf_num[kk][k]<<"\n";
    }

}

    FILE *fp;
    fp=fopen("data-peference-scan.txt","wt");
    if(fp==NULL)
    {
        fprintf(stderr,"cannot open input file in.list !\n");
        exit(1);
    }
    for (int i=0;i<simu_Time;i++)
    {
        for (int j=0;j<simu_num;j++)
            fprintf(fp,"%d  ",inf_num[j][i]);
        fprintf(fp,"\n");
    }
    fclose(fp);

    //cout << "Hello world!" << endl;
    return 0;
}
