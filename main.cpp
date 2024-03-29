#include <iostream>
#include <vector>

class Student{

private :
    std::string Nume;
    std::string Prenume;
    int N1;
    int N2;
    int N3;
    int N4;
    int N5;

public:

    Student( std::string Nume, std::string Prenume , int N1 , int N2 , int N3 , int N4 , int N5  )
    {

        this->Nume=Nume;
        this->Prenume=Prenume;
        this->N1=N1;
        this->N2=N2;
        this->N3=N3;
        this->N4=N4;
        this->N5=N5;

    }
private:
    double calcMedie(){

        return (double) ( N1+N2+N3+N4+N5)/5;

    }
    double esteIntegralist(){

        if(  N1>4 &&  N2>4 &&  N3>4 && N4>4 && N5>4 )return 1;
        else return 0;

    }

public:
    int areBursaMerit( ){

        if(this->calcMedie() <9.8  && this->calcMedie()>=8 && this->esteIntegralist() == 1) return 1;
        else return 0;

    }

    int areBursaPerformanta( ){

        if( this->calcMedie() >= 9.8 && this->esteIntegralist() == 1)return 1;
        else return 0;

    }


};

int main(){

    std::vector<Student*>studenti;
    long int n;
    std::string Nume;
    std::string Prenume;
    int N1;
    int N2;
    int N3;
    int N4;
    int N5;

    std::cin>>n;

    for( int i=0 ;i < n ; i++){
        std::cin>> Nume;
        std::cin>> Prenume;
        std::cin>> N1;
        std::cin>> N2;
        std::cin>> N3;
        std::cin>> N4;
        std::cin>> N5;
        studenti.push_back(new Student( Nume, Prenume , N1 , N2 , N3 , N4 , N5 ));
    }
    int performanta=0;
    int merit=0;
    for( auto x: studenti){
        if( x->areBursaPerformanta( )==1  )performanta++;
        if( x->areBursaMerit( )==1)merit++;
    }
    std::cout<<merit<<" "<<performanta;

    return 0;
}