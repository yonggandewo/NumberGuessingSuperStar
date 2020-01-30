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
				printf("╔╮╔═╠╗╔　╗╗╔\n╔╠╔═╠╗╰═╠╯╠╝\n╭╣╦══╦╚╦╠╝╯║\n╚║╠══╣╚╯╝╝║║\n╭╣╠══╣╚╠╦╝╔╯\n╚╚╚　╚╯╚╩╯╝╯╝\nv1.0.14       By INF蒟蒻\n<1>开始游戏  <4>颜色设置\n<2>游戏帮助  <5>模式设置\n<3>更新日志  <6>退出游戏\n");
				inp=getch();
				got=inp-48;
				system("cls");
				break;
			}
			case 1:{
				printf("请选择游戏模式: \n<1>猜大小\n<2>Bulls and Cows\n<3>Mastermind\n<4>返回主页\n");
				inp=getch();
				system("cls");
				switch(inp){
					case '1':{
						int rou=1,ans=rand()%100+1,in,sma=0,big=101;
						if(mod==2){
							printf("猜大小\n");
							do{
								printf("请输入答案:");
								scanf("%d",&ans);
								if(ans<1||ans>100)printf("输入真奇怪!\n");
							}while(ans<1||ans>100);
						}
						system("cls");
						printf("猜大小\n");
						while(1){
							printf("#%d (%d~%d) 请猜:",rou,sma+1,big-1);
							scanf("%d",&in);
							if(in<=sma){
								printf("输入太小!\n");
								continue;
							}
							if(in>=big){
								printf("输入太大!\n");
								continue;
							} 
							if(in==ans)break;
							if(in<ans){
								sma=in;
								printf("小了!\n");
							}
							else{
								big=in;
								printf("大了!\n");
							}
							rou++;
						}
						printf("#%d 你猜到了%d!\n",rou,ans);
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
								printf("请输入答案:");
								scanf("%d",&in);
								if(in<0||in>9999){
									printf("输入真奇怪!\n");
									continue;
								}
								for(int i=0;i<4;i++){
									ans[i]=in%10;
									in/=10;
								}
								same=false;
								for(int i=0;i<4;i++)for(int j=0;j<4;j++)if(i!=j&&ans[i]==ans[j])same=true;
								if(same){
									printf("输入重复啦!\n");
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
							printf("#%d 请猜:",rou);
							scanf("%d",&in);
							if(in<0||in>9999){
								printf("输入真奇怪!\n");
								continue;
							}
							if(end[in]){
								printf("你猜过这个数了!\n");
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
								printf("输入重复啦!\n");
								continue;
							}
							for(int i=0;i<4;i++)if(gue[i]==ans[i])A++;
							for(int i=0;i<4;i++)for(int j=0;j<4;j++)if(i!=j&&gue[i]==ans[j])B++;
							printf("%dA%dB\n",A,B);
							if(A==4)break;
							end[in]=true;
							rou++;
						}
						printf("#%d 你猜到了",rou);
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
								printf("请输入答案:");
								scanf("%d",&in);
								if(in<0||in>9999)printf("输入真奇怪!\n");
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
							printf("#%d 请猜:",rou);
							scanf("%d",&in);
							if(in<0||in>9999){
								printf("输入真奇怪!\n");
								continue;
							}
							if(end[in]){
								printf("你猜过这个数了!\n");
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
						printf("#%d 你猜到了",rou);
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
				printf("猜大小\n    电脑想好1个1~100的数字，不让你知道。你开始猜后，每猜1个数字，电脑就根据这个数字给出“大了”或者“小了”，其中“大了”表示你猜的数比答案大，“小了”表示你猜的数比答案小，直到猜中为止。\n\nBulls and Cows\n    电脑想好1个没有重复数字的4个数，不让你知道。你开始猜后，每猜1个数字，电脑就根据这个数字给出几A几B，其中A前面的数字表示位置正确的数的个数，而B前的数字表示数字正确而位置不对的数的个数。\n    如正确答案为5234，而你猜5346，则是1A2B，其中有1个5的位置对了，记为1A，而3和4这两个数字对了，而位置没对，因此记为2B，合起来就是1A2B。\n    接着猜的人再根据出题者的几A几B继续猜，直到猜中（即4A0B）为止。\n\nMastermind\n    除了上面Bulls and Cows的规则外，如果有出现重复的数字，则重复的数字每个也只能算1次，且以最优的结果为准。\n    例如，如正确答案为5543，猜的人猜5255，则在这里不能认为猜测的第1个5对正确答案第2个，根据最优结果为准的原理和每个数字只能有1次的规则，2个比较后应该为1A1B，第1个5位子正确，记为1A；猜测数字中的第3个5或第4个5和答案的第2个5匹配，只能记为1B。当然，如果有猜5267中的第1个5不能与答案中的第2个5匹配，因此只能记作1A0B。\n");
				inp=getch();
				system("cls");
				got=0;
				break;
			}
			case 3:{
				printf("2018-3-11 v1.0.0\n·游戏雏形诞生\n2018-3-11 v1.0.1\n·加入Bulls and Cows游戏模式\n2018-3-13 v1.0.2\n·加入Mastermind游戏模式\n·修复进入Bulls and Cows模式无法退出的Bug\n2018-3-13 v1.0.3\n·Bulls and Cows和Mastermind阻止重复猜测\n2018-3-16 v1.0.4\n·滚动字幕\n·加入帮助、更新日志、退出等界面\n·修复Mastermind模式重复数字错判的Bug\n2018-03-18 v1.0.5\n·猜大小阻止重复猜测、越界猜测\n2018-03-18 v1.0.6\n·增加颜色设置\n2018-3-20 v1.0.7\n·缩小应用程序内存\n2018-3-20 v1.0.8\n·修复Bulls and Cows错判的Bug\n·颜色设置更全面\n2018-3-20 v1.0.9\n·修复颜色无法设置的Bug\n2018-3-24 v1.0.10\n·游戏操作方法改善\n2018-3-24 v1.0.11\n·允许玩家出题\n2018-3-25 v1.0.12\n·部分界面调整,加入\"猜数\"LOGO\n2018-3-26 v1.0.13\n·取消滚动字幕\n2020-1-30 v1.0.14\n·修复猜大小输出结果的2个BUG\n");
				inp=getch();
				system("cls");
				got=0;
				break;
			}
			case 4:{
				printf("颜色设置\n<0>白色 <3>绿色 <6>青色\n<1>红色 <4>蓝色 <7>灰色\n<2>黄色 <5>紫色 <8>亮白\n");
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
				printf("模式设置\n<1>机出人猜\n<2>人出人猜\n");
				inp=getch();
				if(inp=='1')mod=1;
				else if(inp=='2')mod=2;
				system("cls");
				got=0;
				break;
			}
			case 6:{
				printf("真的要退出游戏吗?\n<1>残忍退出\n<2>继续游戏\n");
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
