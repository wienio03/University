using namespace std;
#include <string>
string NajwiekszeSlowo(string stringArgument){
    int wordCount=0;
    int wordCount_temp=0;
    for(int i=0; i<stringArgument.size(); i++){
        if(stringArgument[i]==' ')wordCount++;
    }
    string stringArray[wordCount+1];
    for(int i=0; i<wordCount+1; i++){
        stringArray[i]="";
    }
    for(int i=0; i<stringArgument.size(); i++){
        if(stringArgument[i]!=' '){
            stringArray[wordCount_temp]+=stringArgument[i];
            if(stringArgument[i+1]==' ')wordCount_temp++;
        }
    }
    string largest=stringArray[0];
    for(int i=0; i<wordCount+1; i++){
        if(stringArray[i]>=largest)largest=stringArray[i];
    }
    return largest;
}
string UsunSlowo(string stringArgument,  int wordNumber) {
    int wordCount = 0;
    int spaceRepetitions=0;
    int firstIndex=0;
    int lastIndex=stringArgument.size()-1;
    string string_result="";
    //getting first index
    for (int i=0; i< stringArgument.size(); i++){
        if(stringArgument[i]==' ')firstIndex++;
        else break;
    }
    //getting last index
    for( int i=stringArgument.size()-1; i>=0; i--){
        if(stringArgument[i]==' ')lastIndex--;
        else break;
    }
    for (int i = 0; i < stringArgument.size(); i++) {
        if (stringArgument[i] == ' '){
            spaceRepetitions++;
            if(spaceRepetitions==1&&i>=firstIndex&&i<=lastIndex)wordCount++;
        }
        if (stringArgument[i] == ' '){
            string_result+=stringArgument[i];
        }
        if(stringArgument[i]!=' ')spaceRepetitions=0;
        if ((wordCount + 1) != wordNumber)string_result+=stringArgument[i];
    }
    return string_result;
}
string NormalizujNapis(string stringArgument){
    string first_stage="";
    string second_stage="";
    int spaceCounter;
    int firstIndex=0;
    int lastIndex=(stringArgument.size()-1);
    //getting first index;
    for(int i=0; i<stringArgument.size(); i++){
        if(stringArgument[i]==' ')firstIndex++;
        else break;
    }
    //getting last index;
    for(int i=stringArgument.size()-1; i>=0; i--){
        if(stringArgument[i]==' ')lastIndex--;
        else break;
    }
//first stage
    for(int i=0; i<stringArgument.size(); i++) {
        if  (i >= firstIndex && i <=lastIndex){
            if(stringArgument[i]==' '){
                spaceCounter++;
                if(spaceCounter==1&&stringArgument[i-1]!='.'&&stringArgument[i-1]!=',')first_stage += stringArgument[i];}
            if(stringArgument[i]=='.'){
                first_stage+=stringArgument[i];
                if(i!=stringArgument.size()-1)first_stage+=' ';
            }
            if(stringArgument[i]==','){
                first_stage+=stringArgument[i];
                if(i!=stringArgument.size()-1)first_stage+=' ';
            }
            if(stringArgument[i]!=' '&&stringArgument[i]!='.'&&stringArgument[i]!=','){
                first_stage+=stringArgument[i];
                spaceCounter=0;
            }
        }
    }
//second stage
    for(int i=0; i<first_stage.size(); i++){
        if(first_stage[i]==' '&&first_stage[i+1]!=','&&first_stage[i+1]!='.')second_stage+=first_stage[i];
        if(first_stage[i]==','||first_stage[i]=='.')second_stage+=first_stage[i];
        if(first_stage[i]!=' '&&first_stage[i]!='.'&&first_stage[i]!=',')second_stage+=first_stage[i];
    }
    return second_stage;
}
string FormatujNapis(string stringArgument, string parametr1, string parametr2, string parametr3){
    string format="";
    string string_result="";
    string w_string="";
    string W_string="";
    string W_added="";
    string result_temp="";
    int p_repetitions;
    int u_amount;
    int m;
    int removed_amount;
    //checking what operation
    for(int i=0; i<stringArgument.size(); i++){
        if(stringArgument[i]!='{'&&stringArgument[i]!='}')string_result+=stringArgument[i];
        if(stringArgument[i]=='{'){
            int j=i+1;
            while(stringArgument[j]!='}'){
                format+=stringArgument[j];
                j++;
            }
        }
        //{p:n:c}
        if(format[0]=='p'){
            p_repetitions=format[2]-'0';
            for(int k=0; k<p_repetitions; k++){
                string_result+=format[4];
            }
            format="";
            i+=6;
            if(i>stringArgument.size()-1)i=stringArgument.size()-1;
        }
        //{u:n}
        if(format[0]=='u'){
            u_amount=format[2]-'0';
            i+=(u_amount+4);
            if(i>stringArgument.size()-1)i=stringArgument.size()-1;
            format="";
        }
        //{w:n}
        if(format[0]=='w'){
            if(format[2]=='1')w_string+=parametr1;
            if(format[2]=='2')w_string+=parametr2;
            if(format[2]=='3')w_string+=parametr3;
            i+=4;
            if(i>stringArgument.size()-1)i=stringArgument.size()-1;
            for(int k=0; k<w_string.size(); k++){
                string_result+=w_string[k];
            }
            format="";
            w_string="";
        }
        //{W:n:m}
        if(format[0]=='W'){
            if(format[2]=='1')W_string+=parametr1;
            if(format[2]=='2')W_string+=parametr2;
            if(format[2]=='3')W_string+=parametr3;
            m=format[4]-'0';
            i+=6;
            if(i>stringArgument.size()-1)i=stringArgument.size()-1;
            if(m>W_string.size()){
                for(int k=0; k<m; k++){
                    if(k>W_string.size()-1) W_added+=' ';
                    else W_added+=W_string[k];
                }
            }
            else if(m<W_string.size()){
                for(int k=0; k<m; k++){
                    W_added+=W_string[k];
                }
            }
            for(int k=0; k<W_added.size(); k++){
                string_result+=W_added[k];
            }
            format="";
            W_string="";
            W_added="";
        }
        //{U:n}
        if(format[0]=='U'){
            int difference_U;
            removed_amount=format[2]-'0';
            difference_U=string_result.size()-removed_amount;
            if(difference_U<0)difference_U=0;
            string_result.resize(difference_U);
            format="";
            i+=4;
            if(i>stringArgument.size()-1)i=stringArgument.size()-1;
        }
    }
    return string_result;
}
