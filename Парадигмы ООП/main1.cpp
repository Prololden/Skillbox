#include <iostream>

#include <vector>



class Talent {

public:

    virtual void invoke() = 0;

};



class Dancing : public Talent {

public:

    virtual void invoke() {

        std::cout << "It can \"Dance\"" << std::endl;

    }

};

class Swimming : public Talent {

public:

    virtual void invoke() {

        std::cout << "It can \"Swim\"" << std::endl;

    }

};

class Counting : public Talent {

public:

    virtual void invoke() {

        std::cout << "It can \"Count\", smart Dog." << std::endl;

    }

};



class Dog {

public:

    Dog(std::string name) : name_(name) {



    }

    void add(Talent* talent) {

        talents_.push_back(talent);

    }

    void show_talents() {

        std::cout << "This is " << name_ << " and it has some talents:" << std::endl;

        for (int i = 0; i < talents_.size(); ++i) {

            std::cout << "\t";

            talents_[i]->invoke();

        }



    }

    ~Dog()

    {

        for (int i = 0; i < talents_.size(); ++i) {

            delete talents_[i];

        }

    }



private:

    std::string name_;

    std::vector<Talent*> talents_;

};



int main() {

    Dog d("Steve");



    d.add(new Dancing);

    d.add(new Swimming);

    d.show_talents();



    return 0;

}