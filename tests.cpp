#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <stdlib.h>
#include <cmath>
#include <random>
#include <assert.h>

#include "lint.h"

using namespace std;
using apa::lint;

#define THROW_IF(val) if (val) std::cout << "error in " << __FUNCTION__ << endl;
#include "lint.h"


void sum_positive_positive()
{
    int a = 35345;
    int b = 25354634;
    int real_result = a + b;

    apa::lint number1(a);
    apa::lint number2(b);

    number1 += number2;

    THROW_IF(to_string(real_result) != number1.to_string());
}

void sum_positive_positive_2()
{
    int a = 457456745;
    int b = 34;
    int real_result = a + b;

    apa::lint number1(a);
    apa::lint number2(b);

    apa::lint result = number1 + number2;

    THROW_IF(to_string(real_result) != result.to_string());
}

void sum_positive_positive_3()
{
    int a = 9999;
    int b = 9999;
    int real_result = a + b;

    apa::lint number1(a);
    apa::lint number2(b);

    apa::lint result = number1 + number2;

    THROW_IF(to_string(real_result) != result.to_string());
}

void sum_negative_negative()
{
    int a = -9999;
    int b = -9999;
    int real_result = a + b;

    apa::lint number1(a);
    apa::lint number2(b);

    apa::lint result = number1 + number2;

    THROW_IF(to_string(real_result) != result.to_string());
}

void sum_negative_negative_2()
{
    int a = -6546756;
    int b = -34;
    int real_result = a + b;

    apa::lint number1(a);
    apa::lint number2(b);

    number1 += number2;

    THROW_IF(to_string(real_result) != number1.to_string());
}

void sum_positive_negative()
{
    int a = 1050;
    int b = -700;
    int real_result = a + b;

    apa::lint number1(a);
    apa::lint number2(b);

    number1 += number2;

    THROW_IF(to_string(real_result) != number1.to_string());
}

void sum_negative_positive()
{
    int a = -700;
    int b = 500;
    int real_result = a + b;

    apa::lint number1(a);
    apa::lint number2(b);

    number1 += number2;

    THROW_IF(to_string(real_result) != number1.to_string());
}

void diff_positive_negative()
{
    int a = 6546756;
    int b = -34;
    int real_result = a - b;

    apa::lint number1(a);
    apa::lint number2(b);

    number1 -= number2;

    THROW_IF(to_string(real_result) != number1.to_string());
}

void diff_positive_negative_2()
{
    int a = 23;
    int b = -3435;
    int real_result = a - b;

    apa::lint number1(a);
    apa::lint number2(b);

    apa::lint result = number1 - number2;

    THROW_IF(to_string(real_result) != result.to_string());
}

void diff_positive_negative_3()
{
    int a = 2323;
    int b = -3435;
    int real_result = a - b;

    apa::lint number1(a);
    apa::lint number2(b);

    apa::lint result = number1 - number2;

    THROW_IF(to_string(real_result) != result.to_string());
}

void diff_eqaul_negative()
{
    int a = -3435;
    int b = -3435;
    int real_result = a - b;

    apa::lint number1(a);
    apa::lint number2(b);

    number1 -= number2;

    THROW_IF(to_string(real_result) != number1.to_string());
}

void diff_eqaul_negative_positive()
{
    int a = -3435;
    int b = 3435;
    int real_result = a - b;

    apa::lint number1(a);
    apa::lint number2(b);

    number1 -= number2;

    THROW_IF(to_string(real_result) != number1.to_string());
}

void diff_eqaul_positiev_negative()
{
    int a = 3435;
    int b = -3435;
    int real_result = a - b;

    apa::lint number1(a);
    apa::lint number2(b);

    number1 -= number2;

    THROW_IF(to_string(real_result) != number1.to_string());
}

void diff_negarive_negative()
{
    int a = -13435;
    int b = -3435;
    int real_result = a - b;

    apa::lint number1(a);
    apa::lint number2(b);

    number1 -= number2;

    THROW_IF(to_string(real_result) != number1.to_string());
}

void diff_negarive_negative_2()
{
    int a = -13435;
    int b = -343522;
    int real_result = a - b;

    apa::lint number1(a);
    apa::lint number2(b);

    number1 -= number2;

    THROW_IF(to_string(real_result) != number1.to_string());
}

void diff_positive_positive()
{
    int a = 3535;
    int b = 347567;
    int real_result = a - b;

    apa::lint number1(a);
    apa::lint number2(b);

    number1 -= number2;

    THROW_IF(to_string(real_result) != number1.to_string());
}

void diff_positive_positive_2()
{
    int a = 353545657;
    int b = 3475673;
    int real_result = a - b;

    apa::lint number1(a);
    apa::lint number2(b);

    number1 -= number2;

    THROW_IF(to_string(real_result) != number1.to_string());
}

void diff_positive_positive_3()
{
    int a = 353545657;
    int b = 353545657;
    int real_result = a - b;

    apa::lint number1(a);
    apa::lint number2(b);

    number1 -= number2;

    THROW_IF(to_string(real_result) != number1.to_string());
}

void sum_zero_zero()
{
    int a = 0;
    int b = 0;
    int real_result = a + b;

    apa::lint number1(a);
    apa::lint number2(b);

    number1 += number2;

    THROW_IF(to_string(real_result) != number1.to_string());
}

void multiplication_positive_positive()
{
    long long a = 4756745;
    long long b = 56;
    long long real_result = a * b;

    apa::lint number1(a);
    apa::lint number2(b);

    number1 *= number2;

    THROW_IF(to_string(real_result) != number1.to_string());
}

void multiplication_positive_negative()
{
    long long a = 4756745;
    long long b = -56346346;
    long long real_result = a * b;

    apa::lint number1(a);
    apa::lint number2(b);

    number1 *= number2;

    THROW_IF(to_string(real_result) != number1.to_string());
}

void multiplication_negative_positive()
{
    long long a = -14756745;
    long long b = 343000000;
    long long real_result = a * b;

    apa::lint number1(a);
    apa::lint number2(b);

    number1 *= number2;

    THROW_IF(to_string(real_result) != number1.to_string());
}

void multiplication_negative_negative()
{
    long long a = -1475600;
    long long b = -3430000;
    long long real_result = a * b;

    apa::lint number1(a);
    apa::lint number2(b);

    number1 *= number2;

    THROW_IF(to_string(real_result) != number1.to_string());
}

void multiplication_zero_negative()
{
    long long a = 0;
    long long b = -3430000;
    long long real_result = a * b;

    apa::lint number1(a);
    apa::lint number2(b);

    number1 *= number2;

    THROW_IF(to_string(real_result) != number1.to_string());
}

void multiplication_zero_zero()
{
    long long a = 0;
    long long b = 0;
    long long real_result = a * b;

    apa::lint number1(a);
    apa::lint number2(b);

    number1 *= number2;

    THROW_IF(to_string(real_result) != number1.to_string());
}

void multiplication_long_positive_long_positive()
{
    long long a = 100000000000;
    long long b = 100000000000;
    string real_result = "10000000000000000000000";

    apa::lint number1(a);
    apa::lint number2(b);

    number1 *= number2;

    THROW_IF(real_result != number1.to_string());
}

void multiplication_long_positive_long_negative()
{
    long long a = 3453453656775;
    long long b = -345363486349;
    string real_result = "-1192696794848516843864475";

    apa::lint number1(a);
    apa::lint number2(b);

    number1 *= number2;

    THROW_IF(real_result != number1.to_string());
}

void sum_long_positive_long_positive()
{
    long long a = 7856795673456356845;
    long long b = 304857348753483934;
    string real_result = "8161653022209840779";

    apa::lint number1(a);
    apa::lint number2(b);

    number1 += number2;

    THROW_IF(real_result != number1.to_string());
}

void sum_long_negative_long_positive()
{
    long long a = -7856795673456356845;
    long long b = 3048573487534839344;
    string real_result = "-4808222185921517501";

    apa::lint number1(a);
    apa::lint number2(b);

    number1 += number2;

    THROW_IF(real_result != number1.to_string());
}

void diff_long_positive_long_positive()
{
    std::string a = "3798346883476349853256734963454238673845643";
    std::string b = "2382034203820375203720320375";
    string real_result = "3798346883476347471222531143079034953525268";

    apa::lint number1(a);
    apa::lint number2(b);

    number1 -= number2;

    THROW_IF(real_result != number1.to_string());
}

void diff_long_positive_long_negative()
{
    std::string a = "53987639485632876934876934857649";
    std::string b = "-238742934729342934239234";
    string real_result = "53987639724375811664219869096883";

    apa::lint number1(a);
    apa::lint number2(b);

    number1 -= number2;

    THROW_IF(real_result != number1.to_string());
}

void divistion_positive_negative()
{
    int a = 23952;
    int b = 348;
    int real_result = a / b;

    apa::lint number1(a);
    apa::lint number2(b);

    apa::lint result = number1 / number2;

    THROW_IF(to_string(real_result) != result.to_string());
}

void division_long_negative_long_positive()
{
    std::string a = "-100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001";
    std::string b = "9999999999999999931398190359470212947659194368";
    std::string real_result = "-10000000000000000068601809640529787522961634227";

    apa::lint number1(a);
    apa::lint number2(b);

    number1 /= number2;

    THROW_IF(real_result != number1.to_string());
}

void division_long_positive_long_positive()
{
    std::string a = "34534534534";
    std::string b = "3453453453";
    std::string real_result = "10";

    apa::lint number1(a);
    apa::lint number2(b);

    number1 /= number2;

    THROW_IF(real_result != number1.to_string());
}

void randomTest()
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(-4315, 4654); // define the range

    for (int n = 0; n < 4000; ++n)
    {
        int a = distr(eng);
        int b = distr(eng);
        int op = abs(a % 4);

        apa::lint number1(a);
        apa::lint number2(b);

        int result = 0;

        if (op == 0)
        {
            result = a + b;
            number1 += number2;
        }

        if (op == 1)
        {
            result = a - b;
            number1 -= number2;
        }

        if (op == 2)
        {
            result = a * b;
            number1 *= number2;
        }

        if (op == 3)
        {
            if (b == 0)
            {
                continue;
            }

            result = a / b;
            number1 /= number2;
        }

        if (std::to_string(result) != number1.to_string())
        {
            cout << a << " " << b << " " << abs(a % 4) << endl;
        }
    }
}

void sum_1()
{
    string a = "1999999999999996581379496977317805082168981447252801303926808925536335054612681530024132607";
    string b = "1999999999999996581379496977317805082168981447252801303926808925536335054612681530024132607";
    string real_result = "3999999999999993162758993954635610164337962894505602607853617851072670109225363060048265214";

    apa::lint number1(a);
    apa::lint number2(b);

    number1 += number2;

    THROW_IF(real_result != number1.to_string());
}

void sum_2()
{
    string a = "3999999999999996514347722408245605181819353632493052309886158120154694565487439991397154815";
    string b = "3999999999999996514347722408245605181819353632493052309886158120154694565487439991397154815";
    string real_result = "7999999999999993028695444816491210363638707264986104619772316240309389130974879982794309630";

    apa::lint number1(a);
    apa::lint number2(b);

    number1 += number2;

    //    cout << "real_result = " << real_result << endl;
    //    cout << "my_result = " << number1.to_string() << endl;

    THROW_IF(real_result != number1.to_string());
}

void sum_3()
{
    string a = "5999999999999996447315947839173405281469725817733303315845507314773054076362198452770177023";
    string b = "5999999999999996447315947839173405281469725817733303315845507314773054076362198452770177023";
    string real_result = "11999999999999992894631895678346810562939451635466606631691014629546108152724396905540354046";

    apa::lint number1(a);
    apa::lint number2(b);

    number1 += number2;

    //    cout << "real_result = " << real_result << endl;
    //    cout << "my_result = " << number1.to_string() << endl;

    THROW_IF(real_result != number1.to_string());
}

void sum_4()
{
    string a = "7999999999999996380284173270101205381120098002973554321804856509391413587236956914143199231";
    string b = "7999999999999996380284173270101205381120098002973554321804856509391413587236956914143199231";
    string real_result = "15999999999999992760568346540202410762240196005947108643609713018782827174473913828286398462";

    apa::lint number1(a);
    apa::lint number2(b);

    number1 += number2;

    //    cout << "real_result = " << real_result << endl;
    //    cout << "my_result = " << number1.to_string() << endl;

    THROW_IF(real_result != number1.to_string());
}

void sum_5()
{
    string a = "99999999999999993296822543092780009965037218524025100595934919461835951087475846137302220799";
    string b = "99999999999999993296822543092780009965037218524025100595934919461835951087475846137302220799";
    string real_result = "199999999999999986593645086185560019930074437048050201191869838923671902174951692274604441598";

    apa::lint number1(a);
    apa::lint number2(b);

    number1 += number2;

    //    cout << "real_result = " << real_result << endl;
    //    cout << "my_result = " << number1.to_string() << endl;

    THROW_IF(real_result != number1.to_string());
}

void diff_1()
{
    string a = "-100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001";
    string b = "-100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001";
    string real_result = "0";

    apa::lint number1(a);
    apa::lint number2(b);

    number1 -= number2;

    //        cout << "real_result = " << real_result << endl;
    //        cout << "my_result = " << number1.to_string() << endl;

    THROW_IF(real_result != number1.to_string());
}

void diff_2()
{
    string a = "-98000000000000000067031774569072199900349627814759748994040650805381640489125241538626977793";
    string b = "-98000000000000000067031774569072199900349627814759748994040650805381640489125241538626977793";
    string real_result = "0";

    apa::lint number1(a);
    apa::lint number2(b);

    number1 -= number2;

    //        cout << "real_result = " << real_result << endl;
    //        cout << "my_result = " << number1.to_string() << endl;

    THROW_IF(real_result != number1.to_string());
}

void diff_3()
{
    string a = "39999999999999995307775780164946006975526052966817570417154443623285165761233092296111554559";
    string b = "39999999999999995307775780164946006975526052966817570417154443623285165761233092296111554559";
    string real_result = "0";

    apa::lint number1(a);
    apa::lint number2(b);

    number1 -= number2;

    //            cout << "real_result = " << real_result << endl;
    //            cout << "my_result = " << number1.to_string() << endl;

    THROW_IF(real_result != number1.to_string());
}

void diff_4()
{
    string a = "39999999999999995307775780164946006975526052966817570417154443623285165761233092296111554559";
    string b = "39999999999999995307775780164946006975526052966817570417154443623285165761233092296111554559";
    string real_result = "0";

    apa::lint number1(a);
    apa::lint number2(b);

    number1 -= number2;

    //            cout << "real_result = " << real_result << endl;
    //            cout << "my_result = " << number1.to_string() << endl;

    THROW_IF(real_result != number1.to_string());
}

void diff_5()
{
    string a = "51999999999999994905585132750512807573428286078259076452910538790995322826481643064349687807";
    string b = "51999999999999994905585132750512807573428286078259076452910538790995322826481643064349687807";
    string real_result = "0";

    apa::lint number1(a);
    apa::lint number2(b);

    number1 -= number2;

    //            cout << "real_result = " << real_result << endl;
    //            cout << "my_result = " << number1.to_string() << endl;

    THROW_IF(real_result != number1.to_string());
}

void diff_6()
{
    string a = "99999999999999993296822543092780009965037218524025100595934919461835951087475846137302220799";
    string b = "99999999999999993296822543092780009965037218524025100595934919461835951087475846137302220799";
    string real_result = "0";

    apa::lint number1(a);
    apa::lint number2(b);

    number1 -= number2;

    //            cout << "real_result = " << real_result << endl;
    //            cout << "my_result = " << number1.to_string() << endl;

    THROW_IF(real_result != number1.to_string());
}

void multiplication_1()
{
    string a = "1999999999999996581379496977317805082168981447252801303926808925536335054612681530024132607";
    string b = "1999999999999996581379496977317805082168981447252801303926808925536335054612681530024132607";
    string real_result = "3999999999999986325517987909282907294819612845653404009229829582545503115604922851396725634755782907944720035670423563035461252028199958213205052458205173389723661159879802720616449";

    apa::lint number1(a);
    apa::lint number2(b);

    number1 *= number2;

    //            cout << "real_result = " << real_result << endl;
    //            cout << "my_result = " << number1.to_string() << endl;

    THROW_IF(real_result != number1.to_string());
}

void multiplication_2()
{
    string a = "89999999999999993631981415938141009466785357597823845566138173488744153533102053830437109759";
    string b = "89999999999999993631981415938141009466785357597823845566138173488744153533102053830437109759";
    string real_result = "8099999999999998853756654868865422255682051324811750811713230093706593337668026216006932067939096863031219173295754774081803878618411068635873738754042070091244143444263718881413038081";

    apa::lint number1(a);
    apa::lint number2(b);

    number1 *= number2;

    //            cout << "real_result = " << real_result << endl;
    //            cout << "my_result = " << number1.to_string() << endl;

    THROW_IF(real_result != number1.to_string());
}

void failed_tests()
{
    sum_1();
    sum_2();
    sum_3();
    sum_4();
    sum_5();
    diff_1();
    diff_2();
    diff_3();
    diff_4();
    diff_5();
    diff_6();
    multiplication_1();
    multiplication_2();
}

void testMain()
{
    sum_positive_positive();
    sum_positive_positive_2();
    sum_positive_positive_3();
    sum_negative_negative();
    sum_positive_negative();
    sum_negative_positive();
    sum_long_positive_long_positive();
    sum_zero_zero();
    sum_long_negative_long_positive();
    diff_positive_negative();
    diff_positive_negative_2();
    diff_positive_negative_3();
    diff_eqaul_negative();
    diff_eqaul_negative_positive();
    diff_eqaul_positiev_negative();
    diff_negarive_negative();
    diff_negarive_negative_2();
    diff_positive_positive();
    diff_positive_positive_2();
    diff_positive_positive_3();
    diff_long_positive_long_positive();
    diff_long_positive_long_negative();
    multiplication_positive_positive();
    multiplication_positive_negative();
    multiplication_negative_positive();
    multiplication_negative_negative();
    multiplication_zero_negative();
    multiplication_long_positive_long_positive();
    multiplication_long_positive_long_negative();
    divistion_positive_negative();
    division_long_negative_long_positive();
    division_long_positive_long_positive();
    failed_tests();
    randomTest();
}

int main()
{
    testMain();

    system("pause");

    return 0;
}

