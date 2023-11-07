#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;
string space;

string lower(string str){ //because i didnt want to use libruaries and use .tolower()
    for(int i=0;i<=str.length();i++){
        if(int(str[i])<97){
            str[i]=char(int(str[i])+32);
        } 
    }
    return str;
}
//this function checks to see if an alphabet in the word is the same as your name and which one it is(only counts the first one)
char samec(string name,string word){ 
    char same;
    for (int i=0;i<name.length();i++){
        for(int j=0;j<word.length();j++){
            if(name[i]==word[j]){
                same=word[j];
                return same;
            }
            else{
                same='*';
            }
        }
    }
    return same;
}
//this functions has an array of 100 words that it stores and randomly returns
string wordsamp(){
    string words[]={"lion","Tiger","Elephant","Giraffe","Zebra","Leopard","Dolphin","Whale","Penguin","Panda","Koala","Kangaroo","Gorilla","Rhino","Hippo","hen","Chimpanzee","Octopus","Crocodile","Alligator","Platypus","Ostrich","KomodoDragon","BaldEagle","Peacock","Sloth","Armadillo","Ocelot","RedFox","Seahorse","Jellyfish","Bison","Raccoon","Walrus","Lemur","Meerkat","Hedgehog","Chameleon","Salamander","SeaTurtle","UnitedStates","UnitedKingdom","Canada","Australia","Germany","France","Japan","Brazil","India","SouthAfrica","Russia","China","Mexico","Italy","Spain","Argentina","Sweden","Greece","Norway","Denmark","Turkey","NewZealand","Egypt","Switzerland","Belgium","Netherlands","Portugal","Austria","Chile","SouthKorea","Singapore","Malaysia","Thailand","Vietnam","Ireland","Poland","Finland","Hungary","CzechRepublic","Romania","Ukraine","Philippines","Apple","Banana","Orange","Strawberry","Grape","Watermelon","Mango","Kiwi","Pineapple","Lemon","Peach","Cherry","Blueberry","Raspberry","Pear","Plum","Avocado","Grapefruit","Papaya","Coconut","Apricot","Blackberry","Cranberry","Fig","Guava","Lime","Cantaloupe","Pomegranate","Tangerine","Nectarine","Blackcurrant","Elderberry","PassionFruit","Lychee","StarFruit","Persimmon"};
    srand((unsigned) time(NULL));
    return words[(rand()%100)];
}
//this procedure outputs the relevent hangman state depending on the amount of mistakes
void drawing(int mistakes){
    switch(mistakes){
        case 0 :
            cout<<"\n\t+---+\n\t|   |\n\t    |    \n\t    |\n\t    |\n\t    |\t\n\t=======\n";
            break;
        case 1 :
            cout<<"\n\t+---+\n\t|   |\n\to   |    \n\t    |\n\t    |\n\t    |\t\n\t=======\n";
            break;
        case 2 : 
            cout<<"\n\t+---+\n\t|   |\n\to   |    \n\t|   |\n\t    |\n\t    |\t\n\t=======\n";
            break;
        case 3 :
            cout<<"\n\t+---+\n\t|   |\n\to   |    \n\t|\\  |\n\t    |\n\t    |\t\n\t=======\n";
            break;
        case 4:
            cout<<"\n\t+---+\n\t|   |\n\to   |    \n       /|\\  |\n\t    |\n\t    |\t\n\t=======\n";
            break;
        case 5:
            cout<<"\n\t+---+\n\t|   |\n\to   |    \n       /|\\  |\n       /    |\n\t    |\t\n\t=======\n";
            break;
        case 6:
            cout<<"\n\t+---+\n\t|   |\n\to   |    \n       /|\\  |\n       / \\  |\n\t    |\t\n\t=======\n";
            break;
    }
}
//this functions checks to see if the alphabet is present in the word and updates the spacces relevently
bool decision(char alphabet,string word){
    bool status=false;
    for(int i=0;i<=word.length();i++){
        if(word[i]==alphabet){
            status=true;
            space[i]=alphabet;
        }
    }
    return status;
}
int main(){
    string name,word;//initialise var to store name and random word
    char same,alph,chance='!';//initialise characters t0 store the sane alphabet,entered alphabet and the alphabet that is the same as the one in yor name
    int mistakes =0;//initialise the number of mistakes the user makes
    word=lower(wordsamp());//word stores the random word in lower case
    cout<<"Enter Your Name : "; 
    cin>>name;
    name=lower(name);
    same=samec(name,word);//check for same alphabet
    for(int i=1;i<=word.length();i++){//as many spaces as alphabets
        space=space+"_";
    }
    drawing(mistakes);//make initial drawing
    cout<<endl<<space<<endl;//display spaces
    do{
    cout<<"Enter Your Alphabet : ";
    cin>>alph;
    alph=(int(alph)<97?char(int(alph)+32):alph);//to make sure capital is converted to small
    if(decision(alph,word)==false){//it is preset?
        mistakes++;
        drawing(mistakes);
        if(mistakes==4 && space[0]=='_'){//if too many mistakes a hint is given
            space[0]=word[0];
            cout<<endl<<space<<endl;
        }

    }
    else{
        cout<<endl<<space<<endl;
    }
    
    if (mistakes==6 && same!='*' && chance =='!'){//hang man last chance
        cout<<"You have hanged the man\n";
        cout<<"But you may try again\n";
        cout<<"If you guess correctly \n";
        cout<<"The first alphabet that your name and the word have in common : ";
        cin>>chance;
        if(chance==same){
            cout<<"Congrats !!,you have guesses it correctly \n,you may have another chance "<<endl;
            mistakes--;
            drawing(mistakes);//rebirth
        }
        else{
            cout<<"\nWrong ! it was actually : "<<same<<"\nBye Bye\n";
        }
        
        }
    if(space==word){//to exit loop when word is guesses corectly 
        break;
    }
    }while(mistakes<6);//condition for loop to run
    if(space==word){//if loop is exited becaue of success
        cout<<"\n\n------Congrats On Winning The Game!!!------\n\n";
    }
    else{//if loop is exited because of loss
        cout<<"\n\n------You Lost!!------\n\n";
        cout<<"The word was : "<<word<<endl;
    }
    return 0;//end of program
}