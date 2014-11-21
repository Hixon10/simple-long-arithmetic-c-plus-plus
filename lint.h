#ifndef LINT
#define LINT

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

namespace apa
{
    using namespace std;

    template <typename T>
    class ComparisonOperators
    {
        friend bool operator==(T const& lhs, T const& rhs)
        {
            return lhs.compare(rhs) == 0;
        }

        friend bool operator!=(T const& lhs, T const& rhs)
        {
            return lhs.compare(rhs) != 0;
        }

        friend bool operator<(T const& lhs, T const& rhs)
        {
            return lhs.compare(rhs) < 0;
        }

        friend bool operator>(T const& lhs, T const& rhs)
        {
            return rhs.compare(lhs) < 0;
        }

        friend bool operator<=(T const& lhs, T const& rhs)
        {
            bool result = lhs.compare(rhs) <= 0;
            return result;
        }

        friend bool operator>=(T const& lhs, T const& rhs)
        {
            return rhs.compare(lhs) <= 0;
        }
    };

    class lint : ComparisonOperators<lint>
    {
    public:
        explicit lint(std::string number);

        lint();

        lint(long long number);

        lint(int number);

        lint(double number);

        lint(vector<int> nums, bool is_neg);

        lint(const lint &obj);

        int get_length() const;

        bool is_negative_number() const;

        lint& operator+=(const lint& b);

        lint& operator-=(const lint& b);

        lint& operator*=(const lint& number2);

        lint& operator/=(const lint& b);

        explicit operator bool() const;

        explicit operator int();

        lint operator+() const;

        lint operator-() const;

        int operator[](size_t index) const;

        lint& operator=(const lint& other);

        lint& operator++();

        lint operator++(int);

        lint& operator--();

        lint operator--(int);

        bool cmp(lint const& rhs) const;

        int compare(lint const& rhs) const;

        bool is_zero() const;

        std::string to_string();

    private:
        bool is_negative;
        vector<int> numbers;

        lint abs(lint number) const;

        vector<int> reverse_numbers(vector<int> const& numbers) const;

        void make_equal_length(const lint& b, vector<int> & number1, vector<int> & number2) const;

        void string_to_vector(std::string const& number);

        void integer_to_vector(long long a);
    };

    lint abs(lint number);

    lint pow(lint a, int n);

    std::ostream& operator<<(std::ostream& os, const lint& obj);

    std::istream& operator>>(std::istream& is, lint& obj);

    lint operator+(const lint& lhs, const lint& rhs);

    lint operator-(const lint& lhs, const lint& rhs);

    lint operator*(const lint& lhs, const lint& rhs);

    lint operator/(const lint& lhs, const lint& rhs);
}

#endif /* LINT */