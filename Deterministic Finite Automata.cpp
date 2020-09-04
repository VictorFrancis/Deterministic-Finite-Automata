#include<iostream>
#include<string>

using namespace std;

void GetCharacters(int &numberOfCharacters, char* &characters){



    cout<<"Enter number of Characters: "<<endl;
    cin>>numberOfCharacters;

    cout<<"Enter Characters: ";

    characters=new char[numberOfCharacters];

    for(int i=0; i<numberOfCharacters; i++){
        cin>>characters[i];
    //  cout<<"Characters["<<i<<"] ="<<characters[i]<<endl;
    }

}

int getIndex(char z, char *characters, int numberOfCharacters){

    for(int j=0; j<numberOfCharacters; j++){
        if(z==characters[j]){
            return j;
        }

        else{

        }

    }

}

void GetTransitions(int numberOfTransitions, int numberOfCharacters, int numberOfStates, int** &Transitions, char *characters){

    int x,y,t;
    char z;

    cout<<"Enter Transitions: ";

    Transitions=new int*[numberOfCharacters];

    for(int i=0; i<numberOfStates; i++){

        Transitions[i]=new int[numberOfStates];
    }

    for(int i=0; i<numberOfTransitions; i++){
        cin>>x>>y>>z;

        t=getIndex(z,characters,numberOfCharacters);
        Transitions[x][t]=y;
       //out<<"Transitions["<<x<<"]["<<t<<"]"<<"="<<y<<endl;
       //out<<Transitions[x][t];

    }

}


void GetFinalStates(int numberOfFinalStates, int* &FinalStates){

    cout<<"Enter Final States: ";

    FinalStates=new int[numberOfFinalStates];

    for(int i=0; i<numberOfFinalStates; i++){
        cin>>FinalStates[i];
    }
}

void GetInputString(string &input){

    cout<<"Enter Input Strings: ";
    cin>>input;

}

void DeleteDynamics(int numberOfTransitions,int numberOfStates, int** &Transitions, char* &characters, int* &FinalStates){

    for(int i=0; i<numberOfStates; i++){

        delete[] Transitions[i];
    }

    delete[] Transitions;

    delete[] characters;
    delete[] FinalStates;

}

bool CheckDFA(int numberOfStates, int numberOfCharacters, int **Transitions){

    bool checkDFAFlag;

    for(int i=0; i<numberOfStates; i++){
        for(int j=0; j<numberOfCharacters; j++){
            for(int k=0; k<numberOfStates; k++){
                if(Transitions[i][j]==k){
                    checkDFAFlag=true;
                }
                else{
                    checkDFAFlag=false;
                }
            }
        }
    }



    return checkDFAFlag;


}

bool CheckInputString(string input, int numberOfCharacters, int numberOfStates, int numberOfFinalStates, int **Transitions, int *FinalStates){

    int currentState=0;
    //int nextState=currentState+1;

    bool stringAcceptFlag;
    int inputSize = input.size();

    if(inputSize==0){
        cout<<"Empty String"<<endl;

        stringAcceptFlag=false;

    }


    else{
        for(int i=0; i<inputSize; i++){
            for(int j=0; j<numberOfCharacters; j++){
                for(int k=0; k<numberOfStates; k++){
                    if(Transitions[currentState][input[i]]=i){
                    currentState=i;

                    }

                    else{
                        stringAcceptFlag=false;
                    }
                }
            }
        }

        for(int k=0; k<numberOfFinalStates; k++){
            if(currentState==FinalStates[k]){
                stringAcceptFlag=true;
            }
            else{
                stringAcceptFlag=false;
            }
        }
    }

    return stringAcceptFlag;
}

bool LanguageCheck(int numberOfStates, int numberOfCharacters, int numberOfFinalStates, int **Transitions, int *FinalStates){

    int currentState=0;
    //int nextState=currentState+1;

    bool finalStateReachableFlag;

    for(int i=0; i<numberOfStates; i++){
        for(int j=0; j<numberOfCharacters; j++){
            if(Transitions[currentState][j]==i){
                currentState=i;
            }

            else{

            }
        }
    }

    for(int k=0; k<numberOfFinalStates; k++){
        if(currentState==FinalStates[k]){
            finalStateReachableFlag=true;
        }

        else{
            finalStateReachableFlag=false;
        }
    }

    return finalStateReachableFlag;


}


int main(){

    int numberOfStates, numberOfTransitions, numberOfFinalStates;
    int *FinalStates;
    int **Transitions;

    cout<<"Enter number of States, Transition, Final State: ";
    cin>>numberOfStates>>numberOfTransitions>>numberOfFinalStates;

    int initialState=0;


    int numberOfCharacters;
    char *characters;


    GetCharacters(numberOfCharacters,characters);
    //cout<<"No. of characters"<<numberOfCharacters<<endl;
    //cout<<"Characters = "<<characters[0]<<characters[1]<<endl;

    GetTransitions(numberOfTransitions,numberOfCharacters,numberOfStates,Transitions,characters);


    GetFinalStates(numberOfFinalStates,FinalStates);

    string input;

    GetInputString(input);

    cout<<endl;

    if(CheckDFA(numberOfStates,numberOfCharacters,Transitions)==true){
       if(CheckInputString(input,numberOfCharacters,numberOfStates,numberOfFinalStates,Transitions,FinalStates)==true){

            cout<<"DFA accepts the input String"<<endl;
       }

       else{
            if(LanguageCheck(numberOfStates,numberOfCharacters,numberOfFinalStates,Transitions,FinalStates)==true){
                cout<<"DFA rejects the input string"<<endl;
            }

            else{
                cout<<"DFA does not accept any string"<<endl;
            }
       }

    }

    else{
        cout<<"Not A DFA"<<endl;
    }


    DeleteDynamics(numberOfTransitions,numberOfStates,Transitions,characters,FinalStates);

    return 0;
}
