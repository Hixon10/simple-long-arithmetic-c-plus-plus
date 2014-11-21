#include <string>
#include <sstream>
#include <vector>
#include "lint.h"

namespace apa
{
    lint::lint(std::string number)
    {
        string_to_vector(number);
    }

    lint::lint()
    {
        integer_to_vector(0);
    }

    lint::lint(long long number)
    {
        integer_to_vector(number);
    }

    lint::lint(int number)
    {
        integer_to_vector(static_cast<long long>(number));
    }

    lint::lint(double number)
    {
        std::string str = std::to_string(std::trunc(number));
        std::string result = str.substr(0, str.size() - 7);
        string_to_vector(result);
    }

    lint::lint(vector<int> nums, bool is_neg)
    {
        numbers = nums;
        is_negative = is_neg;
    }

    lint::lint(const lint &obj) {
        is_negative = obj.is_negative_number();

        for (int t : obj.numbers)
        {
            numbers.push_back(t);
        }
    }

    int lint::get_length() const
    {
        return numbers.size();
    }

    bool lint::is_negative_number() const
    {
        return is_negative;
    }

    lint& lint::operator+=(const lint& b)
    {
        if (!is_negative_number() && b.is_negative_number())
        {
            lint temp(b);
            temp = abs(temp);

            return operator-=(temp);
        }

        if (is_negative_number() && !b.is_negative_number())
        {
            lint temp_this = lint(*this);
            temp_this.is_negative = false;

            lint temp = lint(b);
            temp -= temp_this;
            *this = temp;

            return *this;
        }

        vector<int> number1;
        vector<int> number2;

        make_equal_length(b, number1, number2);

        vector<int> result;
        int rest = 0;

        for (int i = number1.size() - 1; i >= 0; --i)
        {
            int sum = number1[i] + number2[i] + rest;

            if (sum > 9)
            {
                rest = 1;
                sum -= 10;
            }
            else
            {
                rest = 0;
            }

            result.push_back(sum);
        }

        if (rest > 0)
        {
            result.push_back(rest);
        }

        vector<int> reverse_result = reverse_numbers(result);

        (*this).numbers = reverse_result;

        return *this;
    }

    lint& lint::operator-=(const lint& b)
    {
        if (!is_negative_number() && b.is_negative_number())
        {
            return (*this).operator+=(abs(b));
        }

        if (is_negative_number() && !b.is_negative_number())
        {
            lint temp(b);
            temp.is_negative = true;
            return (*this).operator+=(temp);
        }

        vector<int> number1;
        vector<int> number2;

        make_equal_length(b, number1, number2);

        int is_number1_more_than_number2 = 0;

        for (unsigned int i = 0; i < number1.size(); ++i)
        {
            if (number1[i] > number2[i])
            {
                is_number1_more_than_number2 = 1;
                break;
            }
            else if (number1[i] < number2[i])
            {
                is_number1_more_than_number2 = 2;
                break;
            }
        }

        if (is_number1_more_than_number2 == 0)
        {
            vector<int> t;
            t.push_back(0);
            numbers = t;
            return *this;
        }

        vector<int> result;

        if (is_number1_more_than_number2 == 1)
        {
            for (int i = number1.size() - 1; i >= 0; --i)
            {
                if (number1[i] < number2[i])
                {
                    number1[i] += 10;
                    number1[i - 1] -= 1;
                }

                int r = number1[i] - number2[i];

                result.push_back(r);
            }
        }
        else if (is_number1_more_than_number2 == 2)
        {
            for (int i = number2.size() - 1; i >= 0; --i)
            {
                if (number2[i] < number1[i])
                {
                    number2[i] += 10;
                    number2[i - 1] -= 1;
                }

                int r = number2[i] - number1[i];

                result.push_back(r);
            }
        }

        bool can_copy = false;
        vector<int> result_without_zero;

        for (int i = result.size() - 1; i >= 0; --i)
        {
            if (result[i] != 0)
            {
                can_copy = true;
            }

            if (can_copy)
            {
                result_without_zero.push_back(result[i]);
            }
        }

        (*this).numbers = result_without_zero;

        if (!is_negative_number() && !b.is_negative_number())
        {
            if (is_number1_more_than_number2 == 2)
            {
                is_negative = true;
            }
        }

        if (is_negative_number() && b.is_negative_number())
        {
            if (is_number1_more_than_number2 == 2)
            {
                is_negative = false;
            }
        }

        return *this;
    }

    lint& lint::operator*=(const lint& number2)
    {
        vector<int> a = reverse_numbers(numbers);
        vector<int> b = reverse_numbers(number2.numbers);

        vector<int> c(a.size() + b.size(), 0);

        for (size_t i = 0; i < a.size(); ++i)
        {
            int carry = 0;

            for (unsigned int j = 0; j < b.size() || carry; ++j)
            {
                long long cur = c[i + j] + a[i] * 1ll * (j < b.size() ? b[j] : 0) + carry;

                c[i + j] = int(cur % 10);
                carry = int(cur / 10);
            }
        }

        while (c.size() > 1 && c.back() == 0)
        {
            c.pop_back();
        }

        vector<int> result = reverse_numbers(c);

        numbers = result;

        if (is_negative_number() && !number2.is_negative_number())
        {
            is_negative = true;
        }
        else if (!is_negative_number() && number2.is_negative_number())
        {
            is_negative = true;
        }
        else
        {
            is_negative = false;
        }

        return *this;
    }

    lint& lint::operator/=(const lint& number2)
    {
        if (number2.is_zero())
        {
            int d = 4 - 4;
            int a = 4 / d;
            numbers.push_back(a);
        }

        if (is_zero())
        {
            vector<int> temp;
            temp.push_back(0);
            numbers = temp;
            is_negative = false;
            return *this;
        }

        bool second_number_more_then_first_number = abs(*this).cmp(abs(number2));

        if (second_number_more_then_first_number)
        {
            vector<int> temp;
            temp.push_back(0);
            numbers = temp;
            is_negative = false;
            return *this;
        }

        vector<int> res;
        for (int i = (*this).get_length() - 1; i >= 0; --i)
        {
            res.push_back(0);
        }

        lint current_value(0);
        for (int i = 0; i < (*this).get_length(); ++i)
        {
            current_value = current_value * 10;
            current_value.numbers[current_value.get_length() - 1] = (*this).numbers[i];

            int x = 0;
            int left_index = 0;
            int right_index = 10;

            while (left_index <= right_index)
            {
                int middle = (left_index + right_index) >> 1;
                
                lint cur = abs(number2) * middle;
                
                if (abs(cur) <= abs(current_value))
                {
                    x = middle;
                    left_index = middle + 1;
                }
                else 
                {
                    right_index = middle - 1;
                }
            }

            res[i] = x;
            current_value = current_value - abs(number2) * x;
        }

        res = reverse_numbers(res);

        while (res.size() > 1 && res.back() == 0)
        {
            res.pop_back();
        }

        res = reverse_numbers(res);

        numbers = res;

        if (is_negative_number() && !number2.is_negative_number())
        {
            is_negative = true;
        }
        else if (!is_negative_number() && number2.is_negative_number())
        {
            is_negative = true;
        }
        else
        {
            is_negative = false;
        }

        return *this;
    }

    lint::operator bool() const
    {
        return !is_zero();
    }

    lint::operator int()
    {
        return std::stoi((*this).to_string());
    }

    lint lint::operator+() const
    {
        lint temp(*this);
        return temp;
    }

    lint lint::operator-() const
    {
        lint temp(*this);

        if (is_negative_number())
        {
            temp.is_negative = false;
        }
        else
        {
            temp.is_negative = true;
        }
        
        return temp;
    }

    int lint::operator[](size_t index) const
    {
        return numbers[index];
    }

    lint& lint::operator=(const lint& other)
    {
        if (this != &other)
        {
            numbers = other.numbers;
            is_negative = other.is_negative_number();
        }
        return *this;
    }

    lint& lint::operator++()
    {
        lint one(1);
        (*this) += one;
        return *this;
    }

    lint lint::operator++(int) {
        lint tmp(*this);
        operator++();
        return tmp;
    }

    lint& lint::operator--()
    {
        lint one(1);
        (*this) -= one;
        return *this;
    }

    lint lint::operator--(int) {
        lint tmp(*this);
        operator--();
        return tmp;
    }

    bool lint::cmp(lint const& rhs) const
    {
        if (is_negative_number() && !rhs.is_negative_number())
        {
            return true;
        }

        if (!is_negative_number() && rhs.is_negative_number())
        {
            return false;
        }

        if (get_length() < rhs.get_length())
        {
            return true;
        }

        if (get_length() > rhs.get_length())
        {
            return false;
        }

        for (int i = 0; i < get_length(); ++i)
        {
            if (numbers[i] < rhs[i])
            {
                if (is_negative_number())
                {
                    return false;
                }
                return true;
            }
            else if (numbers[i] > rhs[i])
            {
                if (is_negative_number())
                {
                    return true;
                }
                return false;
            }
        }

        return false;
    }

    int lint::compare(lint const& rhs) const
    {
        if ((*this).cmp(rhs))
        {
            return -1;
        }
        else if (rhs.cmp(*this))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    lint lint::abs(lint number) const
    {
        number.is_negative = false;
        return number;
    }

    bool lint::is_zero() const
    {
        if (numbers.size() == 1 && numbers[0] == 0)
        {
            return true;
        }

        return false;
    }

    std::string int_to_string(int i)
    {
        std::stringstream ss;
        std::string s;
        ss << i;
        s = ss.str();

        return s;
    }

    std::string lint::to_string()
    {
        std::string result = "";

        if (is_negative_number() && !is_zero())
        {
            result += "-";
        }

        for (int i = 0; i < get_length(); ++i)
        {
            int a = (*this)[i];
            result += int_to_string(a);
        }

        return result;
    }

    vector<int> lint::reverse_numbers(vector<int> const& numbers) const
    {
        vector<int> reverse_result;

        for (int i = numbers.size() - 1; i >= 0; --i)
        {
            reverse_result.push_back(numbers[i]);
        }

        return reverse_result;
    }

    void lint::make_equal_length(lint const& b, vector<int>& number1, vector<int>& number2) const
    {
        int diff_length = get_length() - b.get_length();

        if (diff_length > 0)
        {
            number1 = (*this).numbers;

            for (int i = 0; i < diff_length; ++i)
            {
                number2.push_back(0);
            }

            for (int i = 0; i < b.get_length(); ++i)
            {
                number2.push_back(b[i]);
            }
        }
        else if (diff_length < 0)
        {
            for (int i = 0; i < b.get_length(); ++i)
            {
                number2.push_back(b[i]);
            }

            for (int i = 0; i < (diff_length * (-1)); ++i)
            {
                number1.push_back(0);
            }

            for (int i = 0; i < get_length(); ++i)
            {
                number1.push_back((*this)[i]);
            }
        }
        else
        {
            for (int i = 0; i < b.get_length(); ++i)
            {
                number1.push_back((*this)[i]);
                number2.push_back(b[i]);
            }
        }
    }

    void lint::string_to_vector(std::string const& number)
    {
        unsigned int from = 0;

        if (number[0] == '-')
        {
            is_negative = true;
            from = 1;
        }
        else
        {
            is_negative = false;
        }

        for (unsigned int i = from; i < number.length(); ++i)
        {
            int ia = number[i] - '0';
            numbers.push_back(ia);
        }
    }

    void lint::integer_to_vector(long long a)
    {
        if (a < 0)
        {
            is_negative = true;
            a = (-1) * a;
        }
        else
        {
            is_negative = false;
        }

        if (a == 0)
        {
            numbers.push_back(0);
        }

        vector<int> temp;

        while (a)
        {
            int x = a % 10;
            a /= 10;
            temp.push_back(x);
        }

        for (int i = temp.size() - 1; i >= 0; --i)
        {
            numbers.push_back(temp[i]);
        }
    }

    lint abs(lint number)
    {
        lint n(number);
        lint zero(0);

        bool is_less = n.cmp(zero);

        if (is_less)
        {
            n *= lint(-1);
        }
        return n;
    }

    lint pow(lint a, int n) {
        lint res(1);

        while (n)
        {
            if (n & 1)
            {
                res *= a;
            }

            a *= a;
            n >>= 1;
        }

        return res;
    }

    std::ostream& operator<<(std::ostream& os, const lint& obj)
    {
        if (obj.is_negative_number())
        {
            os << "-";
        }

        for (int i = 0; i < obj.get_length(); ++i)
        {
            os << obj[i];
        }

        return os;
    }

    std::istream& operator>>(std::istream& is, lint& obj)
    {
        bool is_lead_zeros = true;
        bool is_negative = false;
        vector<int> numbers;

        while (is.good())
        {
            char c = static_cast<char>(is.get());
            int ic = c - '0';

            if (c == '\n')
            {
                break;
            }

            if (c == EOF)
            {
                break;
            }

            if (c == '\0')
            {
                break;
            }

            if (is.good())
            {
                if (c == '-')
                {
                    is_negative = true;
                }
                else if (c == '+')
                {
                    is_negative = false;
                }
                else if (ic == 0 && is_lead_zeros)
                {

                }
                else
                {
                    numbers.push_back(ic);
                    is_lead_zeros = false;
                }
            }
        }

        lint temp(numbers, is_negative);
        obj = temp;

        return is;
    }

    lint operator+(const lint& lhs, const lint& rhs)
    {
        lint temp(lhs);

        return temp += rhs;
    }

    lint operator-(const lint& lhs, const lint& rhs)
    {
        lint temp(lhs);

        return temp -= rhs;
    }

    lint operator*(const lint& lhs, const lint& rhs)
    {
        lint temp(lhs);

        return temp *= rhs;
    }

    lint operator/(const lint& lhs, const lint& rhs)
    {
        lint temp(lhs);

        return temp /= rhs;
    }
}