#include<ctime>
#include<cstdio>
#include<conio.h>
#include<cstdlib> 
int main(){
	srand(time(NULL));
	int got=0,mod=1;
	char inp;
	while(1){
		switch(got){
			case 0:{
				printf("�X�r�X�T�d�[�X���[�[�X\n�X�d�X�T�d�[�t�T�d�s�d�a\n�q�g�j�T�T�j�^�j�d�a�s�U\n�^�U�d�T�T�g�^�s�a�a�U�U\n�q�g�d�T�T�g�^�d�j�a�X�s\n�^�^�^���^�s�^�m�s�a�s�a\nv1.0.14       By INF�X�m\n<1>��ʼ��Ϸ  <4>��ɫ����\n<2>��Ϸ����  <5>ģʽ����\n<3>������־  <6>�˳���Ϸ\n");
				inp=getch();
				got=inp-48;
				system("cls");
				break;
			}
			case 1:{
				printf("��ѡ����Ϸģʽ: \n<1>�´�С\n<2>Bulls and Cows\n<3>Mastermind\n<4>������ҳ\n");
				inp=getch();
				system("cls");
				switch(inp){
					case '1':{
						int rou=1,ans=rand()%100+1,in,sma=0,big=101;
						if(mod==2){
							printf("�´�С\n");
							do{
								printf("�������:");
								scanf("%d",&ans);
								if(ans<1||ans>100)printf("���������!\n");
							}while(ans<1||ans>100);
						}
						system("cls");
						printf("�´�С\n");
						while(1){
							printf("#%d (%d~%d) ���:",rou,sma+1,big-1);
							scanf("%d",&in);
							if(in<=sma){
								printf("����̫С!\n");
								continue;
							}
							if(in>=big){
								printf("����̫��!\n");
								continue;
							} 
							if(in==ans)break;
							if(in<ans){
								sma=in;
								printf("С��!\n");
							}
							else{
								big=in;
								printf("����!\n");
							}
							rou++;
						}
						printf("#%d ��µ���%d!\n",rou,ans);
						inp=getch();
						system("cls");
						break;
					}
					case '2':{
						int ans[6],gue[6],in,A,B,rou=1;
						bool end[15000],same;
						for(int i=0;i<10000;i++)end[i]=false;
						for(int i=1;i<4;i++){
							ans[i]=rand()%10;
							for(int j=0;j<i*i;j++)if(ans[i]==ans[j]%4)ans[i]++;
						}
						if(mod==2){
							printf("Bulls and Cows\n");
							while(1){
								printf("�������:");
								scanf("%d",&in);
								if(in<0||in>9999){
									printf("���������!\n");
									continue;
								}
								for(int i=0;i<4;i++){
									ans[i]=in%10;
									in/=10;
								}
								same=false;
								for(int i=0;i<4;i++)for(int j=0;j<4;j++)if(i!=j&&ans[i]==ans[j])same=true;
								if(same){
									printf("�����ظ���!\n");
									continue;
								}
								break;
							}	
						}
						system("cls");
						printf("Bulls and Cows\n");
						while(1){
							A=0;
							B=0;
							printf("#%d ���:",rou);
							scanf("%d",&in);
							if(in<0||in>9999){
								printf("���������!\n");
								continue;
							}
							if(end[in]){
								printf("��¹��������!\n");
								continue;
							}
							end[in]=true;
							for(int i=0;i<4;i++){
								gue[i]=in%10;
								in/=10;
							}
							same=false;
							for(int i=0;i<4;i++)for(int j=0;j<4;j++)if(i!=j&&gue[i]==gue[j])same=true;
							if(same){
								printf("�����ظ���!\n");
								continue;
							}
							for(int i=0;i<4;i++)if(gue[i]==ans[i])A++;
							for(int i=0;i<4;i++)for(int j=0;j<4;j++)if(i!=j&&gue[i]==ans[j])B++;
							printf("%dA%dB\n",A,B);
							if(A==4)break;
							end[in]=true;
							rou++;
						}
						printf("#%d ��µ���",rou);
						for(int i=3;i>=0;i--)printf("%d",ans[i]);
						printf("!\n");
						inp=getch();
						system("cls");
						break;
					}
					case '3':{	
						int ans[6],gue[6],in,A,B,rou=1;
						bool che[6],end[15000];
						for(int i=0;i<10000;i++)end[i]=false;
						for(int i=0;i<4;i++)che[i]=true;
						for(int i=0;i<4;i++)ans[i]=rand()%10;
						if(mod==2){
							printf("Mastermind\n");
							do{
								printf("�������:");
								scanf("%d",&in);
								if(in<0||in>9999)printf("���������!\n");
							}while(in<0||in>9999);
						}
						for(int i=0;i<4;i++){
							ans[i]=in%10;
							in/=10;
						}
						system("cls");
						printf("Mastermind\n");
						while(1){
							for(int i=0;i<4;i++)che[i]=true;
							A=0;
							B=0;
							printf("#%d ���:",rou);
							scanf("%d",&in);
							if(in<0||in>9999){
								printf("���������!\n");
								continue;
							}
							if(end[in]){
								printf("��¹��������!\n");
								continue;
							}
							end[in]=true;
							for(int i=0;i<4;i++){
								gue[i]=in%10;
								in/=10;
							}
							for(int i=0;i<4;i++)if(gue[i]==ans[i]){
								A++;
								che[i]=false;
							}
							for(int i=0;i<4;i++)for(int j=0;j<4;j++)if(i!=j&&che[i]&&gue[i]==ans[j]){
								B++;
								che[i]=false;
							}
							printf("%dA%dB\n",A,B);
							if(A==4)break;
							rou++;
						}
						printf("#%d ��µ���",rou);
						for(int i=3;i>=0;i--)printf("%d",ans[i]);
						printf("!\n");
						inp=getch();
						system("cls");
						break;
					}
					case '4':{
						got=0;
						system("cls"); 
						break;
					}
				}
				break;
			}
			case 2:{
				printf("�´�С\n    �������1��1~100�����֣�������֪�����㿪ʼ�º�ÿ��1�����֣����Ծ͸���������ָ��������ˡ����ߡ�С�ˡ������С����ˡ���ʾ��µ����ȴ𰸴󣬡�С�ˡ���ʾ��µ����ȴ�С��ֱ������Ϊֹ��\n\nBulls and Cows\n    �������1��û���ظ����ֵ�4������������֪�����㿪ʼ�º�ÿ��1�����֣����Ծ͸���������ָ�����A��B������Aǰ������ֱ�ʾλ����ȷ�����ĸ�������Bǰ�����ֱ�ʾ������ȷ��λ�ò��Ե����ĸ�����\n    ����ȷ��Ϊ5234�������5346������1A2B��������1��5��λ�ö��ˣ���Ϊ1A����3��4���������ֶ��ˣ���λ��û�ԣ���˼�Ϊ2B������������1A2B��\n    ���Ųµ����ٸ��ݳ����ߵļ�A��B�����£�ֱ�����У���4A0B��Ϊֹ��\n\nMastermind\n    ��������Bulls and Cows�Ĺ����⣬����г����ظ������֣����ظ�������ÿ��Ҳֻ����1�Σ��������ŵĽ��Ϊ׼��\n    ���磬����ȷ��Ϊ5543���µ��˲�5255���������ﲻ����Ϊ�²�ĵ�1��5����ȷ�𰸵�2�����������Ž��Ϊ׼��ԭ���ÿ������ֻ����1�εĹ���2���ȽϺ�Ӧ��Ϊ1A1B����1��5λ����ȷ����Ϊ1A���²������еĵ�3��5���4��5�ʹ𰸵ĵ�2��5ƥ�䣬ֻ�ܼ�Ϊ1B����Ȼ������в�5267�еĵ�1��5��������еĵ�2��5ƥ�䣬���ֻ�ܼ���1A0B��\n");
				inp=getch();
				system("cls");
				got=0;
				break;
			}
			case 3:{
				printf("2018-3-11 v1.0.0\n����Ϸ���ε���\n2018-3-11 v1.0.1\n������Bulls and Cows��Ϸģʽ\n2018-3-13 v1.0.2\n������Mastermind��Ϸģʽ\n���޸�����Bulls and Cowsģʽ�޷��˳���Bug\n2018-3-13 v1.0.3\n��Bulls and Cows��Mastermind��ֹ�ظ��²�\n2018-3-16 v1.0.4\n��������Ļ\n�����������������־���˳��Ƚ���\n���޸�Mastermindģʽ�ظ����ִ��е�Bug\n2018-03-18 v1.0.5\n���´�С��ֹ�ظ��²⡢Խ��²�\n2018-03-18 v1.0.6\n��������ɫ����\n2018-3-20 v1.0.7\n����СӦ�ó����ڴ�\n2018-3-20 v1.0.8\n���޸�Bulls and Cows���е�Bug\n����ɫ���ø�ȫ��\n2018-3-20 v1.0.9\n���޸���ɫ�޷����õ�Bug\n2018-3-24 v1.0.10\n����Ϸ������������\n2018-3-24 v1.0.11\n��������ҳ���\n2018-3-25 v1.0.12\n�����ֽ������,����\"����\"LOGO\n2018-3-26 v1.0.13\n��ȡ��������Ļ\n2020-1-30 v1.0.14\n���޸��´�С��������2��BUG\n");
				inp=getch();
				system("cls");
				got=0;
				break;
			}
			case 4:{
				printf("��ɫ����\n<0>��ɫ <3>��ɫ <6>��ɫ\n<1>��ɫ <4>��ɫ <7>��ɫ\n<2>��ɫ <5>��ɫ <8>����\n");
				inp=getch();
				switch(inp){
					case '0':{
						system("color 07");
						break; 
					}
					case '1':{
						system("color 0C");
						break;
					}
					case '2':{
						system("color 0E");
						break;
					}
					case '3':{
						system("color 0A");
						break;
					}
					case '4':{
						system("color 09");
						break;
					}
					case '5':{
						system("color 0D");
						break;
					}
					case '6':{
						system("color 0B");
						break;
					}
					case '7':{
						system("color 08");
						break;
					}
					case '8':{
						system("color 0F");
						break;
					}
				}
				system("cls");
				got=0;
				break;
			}
			case 5:{
				printf("ģʽ����\n<1>�����˲�\n<2>�˳��˲�\n");
				inp=getch();
				if(inp=='1')mod=1;
				else if(inp=='2')mod=2;
				system("cls");
				got=0;
				break;
			}
			case 6:{
				printf("���Ҫ�˳���Ϸ��?\n<1>�����˳�\n<2>������Ϸ\n");
				inp=getch();
				if(inp=='1')return 0;
				else if(inp=='2')got=0;
				system("cls");
				break;
			}
			default:{
				got=0;
				break;
			}
		}
	}
	return 0;
}
