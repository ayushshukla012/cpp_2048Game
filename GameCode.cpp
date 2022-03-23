#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
const int MAX=2048;

int card[4][4]={0};
static int pattern;
static int score;

//Write about this
int randomGen(){
    int random1=rand()%4;
    return random1;
}

//Write about this
int new_randomGen(){
    int randomEle=rand()%10;
    randomEle=(randomEle==0)?4:2;
    return randomEle;
}

//To win satisfy this
int about_win(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(card[i][j]==MAX){
                    return 1;
                }
            }
        }
        return 0;
}

//To end game satisfy this
int end_game(){
    int game_over=1;
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if(card[i][j]==0 || card[i][j+1]==0 || card[i][j]==card[i][j+1]){
                game_over=0;
                break;
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if(card[i][j]==0 || card[i+1][j]==0 || card[i][j]== card[i+1][j]){
                game_over=0;
            }
        }
    }
    return game_over;
}

//Home Display Code, First Visible Page
void display(){
     int index1,index2,index3,index4;
     while(1){
         index1=randomGen();
         index2=randomGen();
         index3=randomGen();
         index4=randomGen();
         if(index1==index3 && index2==index4){
             continue;
         }
         else{
             break;
         }
     }
    if(pattern == 0){
        cout<<"\t\t\t\t\t********************************************\t\tfull screen from here ^"<<endl;
        cout<<"\t\t\t\t\t********************************************"<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t It's 2048. \t\t"<<endl<<endl;
        cout<<"\t\t\t\t\t********************************************"<<endl;
        cout<<"\t\t\t\t\t********************************************"<<endl<<endl;
        cout<<">>You are most WELCOME to my WORLD. !!"<<endl;
        cout<<"  ::::::::::::::::::::::::::::::::::::::"<<endl<<endl;
        cout<<"# Rules are Simple."<<endl;
        cout<<"---------------------"<<endl<<endl;
        cout<<"1.Use Keyboard Buttons to move."<<endl;
        cout<<"UP-->'w' \t DOWN-->'s' \t LEFT-->'a' \t RIGHT-->'d'"<<endl;
        cout<<"2.Choose a key and Press 'Enter'"<<endl;
        cout<<"3.Use the above given keys to move the tiles in your desired directions."<<endl;
        cout<<"4.Continue to merge until get '2048' ;-)"<<endl<<endl;
        cout<<"\t\t\t\t\t==>>GAME BEGINS... ALL THE BEST. :-)"<<endl<<endl;
        for(int i=0;i<4;i++){
            cout<<"|---------------|"<<endl;
            for(int j=0;j<4;j++){
                cout<<"|";
                if(i==index1 && j==index2){
                    card[i][j]=2;
                    cout<<" "<<2<<" ";
                }
                else if(i==index3 && j==index4){
                    int temp=new_randomGen();
                    card[i][j]=temp;
                    cout<<" "<<temp<<" ";
                }
                else{
                    cout<<"  ";
                }
            }
            cout<<"|"<<endl;
        }
        cout<<"|---------------|"<<endl;
    }
    else{
        for(int i=0;i<4;i++){
            cout<<"|---------------|"<<endl;
            for(int j=0;j<4;j++){
                cout<<"|";
                if(card[i][j]!=0){
                    if(card[i][j]==1024 || card[i][j]==2048)
                        cout<<" "<<card[i][j];
                    if(card[i][j]==128 || card[i][j]==256 || card[i][j]==512)
                        cout<<" "<<card[i][j]<<" ";
                    if(card[i][j]==16 || card[i][j]==32 || card[i][j]==64)
                        cout<<" "<<card[i][j]<<" ";
                    if(card[i][j]==2 || card[i][j]==4 || card[i][j]==8)
                        cout<<" "<<card[i][j]<<" ";
                }
                else{
                    cout<<"  ";
                }
            }
            cout<<"|"<<endl;
        }
        cout<<"|---------------|"<<endl;
    }
 
}
//Adding Element
void add_Element(){
    int index5,index6,flag=0;
    while(1){
        if(flag==1) 
            break;
        index5=randomGen();
        index6=randomGen();
        if(card[index5][index6]==0){
            card[index5][index6]= new_randomGen();
            flag=1;
        }
    }
}

//Left Key Code
void leftkey(){
    int flag=0;
    for(int i=0;i<4;i++){
        int n=0;
        int prev=0;
        for(int j=0;j<4;j++){
            if(n==card[i][j] && n!=0){
                card[i][prev] = 2*n;
                card[i][j]=0;
                score+=2*n;
                n=0;
                flag++;
                continue;
            }
            if(card[i][j]!=0){
                n=card[i][j];
                prev=j;
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<3;k++){
                if(card[i][k]==0 && card[i][k+1]!=0){
                    card[i][k]=card[i][k]^card[i][k+1];
                    card[i][k+1]=card[i][k]^card[i][k+1];
                    card[i][k]=card[i][k]^card[i][k+1];
                    flag++;
                }
            }
        }
    }
    if(flag!=0){
        add_Element();
        pattern++;    
    }
    display();
}

//Right Key Code
void rightkey(){
    int flag=0;
    for(int i=0;i<4;i++){
        int n=0;
        int prev=0;
        for(int j=3;j>=0;j--){
            if (n==card[i][j] && n!=0) {
                card[i][prev] = 2*n;
                card[i][j]=0;
                score+=2*n;
                n=0;
                flag++;
                continue;
            }
            if(card[i][j]!=0){
                n=card[i][j];
                prev=j;
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=3;k>0;k--){
                if(card[i][k]==0 && card[i][k-1]!=0){
                    card[i][k]=card[i][k]^card[i][k-1];
                    card[i][k-1]=card[i][k]^card[i][k-1];
                    card[i][k]=card[i][k]^card[i][k-1];
                    flag++;
                }
            }
        }
    }
    if(flag!=0){
        add_Element();
        pattern++;    
    }
    display();
}

//Up Key Code
void upkey(){
    int flag=0;
    for(int i=0;i<4;i++){
        int n=0;
        int prev=0;
        for(int j=0;j<4;j++){
            if(n==card[j][i] && n!=0){
                card[prev][i] = 2*n;
                card[j][i]=0;
                score+=2*n;
                n=0;
                flag++;
                continue;
            }
            if(card[j][i]!=0){
                n=card[j][i];
                prev=j;
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<3;k++){
                if(card[k][i]==0 && card[k+1][i]!=0){
                    card[k][i]=card[k][i]^card[k+1][i];
                    card[k+1][i]=card[k][i]^card[k+1][i];
                    card[k][i]=card[k][i]^card[k+1][i];
                    flag++;
                }
            }
        }
    }
    if(flag!=0){
        add_Element();
        pattern++;    
    }
    display();
}

//Down Key Code
void downkey(){
    int flag=0;
    for(int i=0;i<4;i++){
        int n=0;
        int prev=0;
        for(int j=3;j>0;j--){
            if(n==card[j][i] && n!=0){
                card[prev][i] = 2*n;
                card[j][i]=0;
                score+=2*n;
                n=0;
                flag++;
                continue;
            }
            if(card[j][i]!=0){
                n=card[j][i];
                prev=j;
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=3;k>0;k--){
                if(card[k][i]==0 && card[k-1][i]!=0){
                    card[k][i]=card[k][i]^card[k-1][i];
                    card[k-1][i]=card[k][i]^card[k-1][i];
                    card[k][i]=card[k][i]^card[k-1][i];
                    flag++;
                }
            }
        }
    }
    if(flag!=0){
        add_Element();
        pattern++;    
    }
    display();
}

//Main Starts here
int main(){
    srand((unsigned)time(NULL));
    char c,ch;
    int ran=0;

    display();
    while(1){
        if(about_win() && !ran){
            ran= !ran;
            cout<<pattern<<"steps"<<endl;
            cout<<"----------------------------------"<<endl;
            cout<<"\t\t"<<"Hurray you WON!!!!!!!!!"<<endl;
            cout<<"Would you like to continue(Y/N)?"<<endl;
            cin>>c;
            cout<<"----------------------------------"<<endl;
            if(c=='N')
                exit(1);
        }
         if(end_game()){
             cout<<"Your Game is Over my Love!!!"<<endl;
             exit(2);
         }
         cout<<"\t\t\t\tEnter your move:";
         cin>>ch;
         switch(ch){
             case 'w':
                upkey();
                break;
            case 's':
                downkey();
                break;
            case 'a':
                leftkey();
                break;
            case 'd':
                rightkey();
                break;
            case 'q':
                exit(1);
            default:
                break;
         }
         cout<<endl<<"Your Score: "<<score<<endl;
    }
    return 0;
}