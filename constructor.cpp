#include<iostream>
#include<string>
using namespace std;
class Movie
{
    public:
    string name;
    string genre;
    float rating;
    Movie()
    {
        name="";
        genre="";
        rating=0;
    }
    Movie(string name,string genre,float rating)
    {
        this->name=name;
        this->genre=genre;
        this->rating=rating;

    }
    Movie(const Movie &original)
    {
        name=original.name;
        genre=original.genre;
        rating=original.rating;
    }
    
    Movie &operator=(const Movie &original)
    {
        name=original.name;
        genre=original.genre;
        rating=original.rating;
        return *this;
    }
    




};


int main()
{
    Movie movie1("the dark knight","action",9.5);
    Movie movie2("the lion king","animated",8);
    Movie movie3;
    Movie movie4(movie1);
    Movie movie5=movie1;
    movie5=movie2;


}