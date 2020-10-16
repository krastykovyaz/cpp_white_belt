// Добавьте в класс Function из задачи «Обратимая функция» обработку умножения ('*') и деления ('/'). Гарантируется отсутствие элементарных операций умножения и деления на 0.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
};

class FunctionPart{
public:
    FunctionPart(char n_sign, double n_value){
        sign = n_sign;
        value = n_value;
    }
    double Apply(double s_value)const{
        if (sign == '+'){
            return s_value + value;
        }
        else if (sign == '-'){
            return s_value - value;
        }
        else if (sign == '/'){
            return s_value / value;
        }
        else
        {
            return s_value * value;
        }
    }
    void Invert(){
        if (sign == '-'){
            sign = '+';
        }
        else if (sign == '+')
        {
            sign = '-';
        }
        else if (sign == '*'){
            sign = '/';
        }
        else if (sign == '/'){
            sign = '*';
        }
    }
private:
    char sign;
    double value;
};

class Function{
public:
    void AddPart(char sign, double value){
        parts.push_back({sign, value});
    }
    double Apply(double value)const {
        for (const FunctionPart & part : parts){
            value = part.Apply(value);
        }
        return value;
    }
    void Invert(){
        for (FunctionPart & part : parts){
            part.Invert();
        }
        reverse(begin(parts), end(parts));
    }
private:
    vector<FunctionPart> parts;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('*', params.a);
  function.AddPart('-', image.freshness * params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

int main() {
  Image image = {10, 2, 6};
  Params params = {4, 2, 6};
  cout << ComputeImageWeight(params, image) << endl;
  cout << ComputeQualityByWeight(params, image, 52) << endl;
  return 0;
}
