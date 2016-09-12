#include "Integer.h"

Integer::Integer() : m_sign(false) {}

Integer::Integer(const std::string& data) : m_sign(false) {
    for (int i = data.size() - 1; i >= 0; --i)
        m_data.push_back(data[i]);
}

Integer::Integer(const std::vector<int>& data) : m_sign(false) {
    for (int i = data.size() - 1; i >= 0; --i)
        m_data.push_back(data[i] + '0');
}

Integer::Integer(int data) : m_sign(false) {
    if (data == 0)
        m_data.push_back('0');
    while (data) {
        m_data.push_back((data % 10) + '0');
        data /= 10;
    }
}

Integer::Integer(const Integer& rhs) : m_sign(false) {
    m_data = rhs.m_data;
}

Integer& Integer::operator = (const Integer& rhs) {
    m_data = rhs.m_data;
    return *this;
}

Integer::~Integer() {}

Integer Integer::operator + (const Integer& rhs) {
    Integer number;
    std::size_t i = 0;
    std::size_t j = 0;
    int carry = 0;

    while (i < m_data.size() && j < rhs.m_data.size()) {
        const int sum = carry + (m_data[i++] - '0' + rhs.m_data[j++] - '0');
        number.m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    while (i < m_data.size()) {
        const int sum = carry + (m_data[i++] - '0');
        number.m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
        if (carry == 0)
            break;
    }

    while (j < rhs.m_data.size()) {
        const int sum = carry + (rhs.m_data[j++] - '0');
        number.m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    while (carry) {
        number.m_data.push_back(carry% 10 + '0');
        carry /= 10;
    }

    return number;
}

Integer Integer::operator + (const std::string& rhs) {
    Integer number;
    std::size_t i = 0;
    int j = rhs.size() - 1;
    int carry = 0;

    while (i < m_data.size() && j >= 0) {
        const int sum = carry + (m_data[i++] - '0') + (rhs[j--]);
        number.m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    while (i < m_data.size()) {
        const int sum = carry + (m_data[i++] - '0');
        number.m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
        if (carry == 0)
            break;
    }

    while (j >= 0) {
        const int sum = carry + (rhs[j--] - '0');
        number.m_data.push_back((sum % 10) + '0');
        carry = sum / 10;        
    }

    while (carry) {
        number.m_data.push_back((carry % 10) + '0');
        carry /= 10;
    }
}

Integer Integer::operator + (const int& rhs) {
    Integer number;
    int carry = rhs;
    for (std::size_t i = 0; i < m_data.size(); ++i) {
        const int sum = carry +  m_data[i] - '0';
        number.m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    while (carry) {
        number.m_data.push_back(carry% 10 + '0');
        carry /= 10;        
    }

    return number;
}

void Integer::operator += (const Integer& rhs) {
    std::size_t i = 0;
    std::size_t j = 0;
    int carry = 0;

    while (i < m_data.size() && j < rhs.m_data.size()) {
        const int sum = carry + (m_data[i] - '0') + (rhs.m_data[j++] - '0');
        m_data[i++] = (sum % 10) + '0';
        carry = sum / 10;
    }

    while (i < m_data.size()) {
        const int sum = carry + (m_data[i] - '0');
        m_data[i++] = (sum % 10) + '0';
        carry = sum / 10;
        if (carry == 0)
            break;
    }

    while (j < rhs.m_data.size()) {
        const int sum = carry + (rhs.m_data[j++] - '0');
        m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    while (carry) {
        m_data.push_back((carry % 10) + '0');
        carry /= 10;
    }
}

void Integer::operator += (const std::string& rhs) {
    std::size_t i = 0;
    int j = rhs.size() - 1;
    int carry = 0;

    while (i < m_data.size() && j >= 0) {
        const int sum = carry + (m_data[i] - '0') + (rhs[j--] - '0');
        m_data[i++] = (sum % 10) + '0';
        carry = sum / 10;
    }

    while (i < m_data.size()) {
        const int sum = carry + (m_data[i] - '0');
        m_data[i++] = (sum % 10) + '0';
        carry = sum / 10;
        if (carry == 0)
            break;
    }

    while (j >= 0) {
        const int sum = carry + (rhs[j--] - '0');
        m_data.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    while (carry) {
        m_data.push_back((carry % 10) + '0');
        carry /= 10;
    }
}

void Integer::operator += (const int& rhs) {
    int carry = rhs;

    for (std::size_t i = 0; i < m_data.size(); ++i) {
        const int sum = carry + m_data[i] - '0';
        m_data[i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    while (carry) {
        m_data.push_back((carry % 10) + '0');
        carry /= 10;
    }
}

#if 0
Integer Integer::operator - (const Integer& rhs) {
    if (m_data == rhs.m_data) {
        Integer number(0);
        return number;
    } else if (m_data < rhs.m_data) {
        m_sign = true;
        Integer number;
        m_subtract(rhs.m_data, m_data, number.m_data);
        return number;
    } else {
        Integer number;
        m_subtract(m_data, rhs.m_data, number.m_data);
        return number;
    }
}
#endif
std::size_t Integer::Size() const {
    return m_data.size();
}
void Integer::Print() const {
    if (m_sign)
        printf("-");
    for (int i = m_data.length() - 1; i >= 0; --i)
        printf("%c", m_data[i]);
    printf("\n");
}

#if 0
void Integer::m_subtract(const std::string& A, const std::string& B, std::string& R) {
    std::size_t i = 0;
    std::size_t j = 0;

    while (i < A.size() && j < B.size()) {
        if (A[i] < B[j]) {
            R.push_back((10 + A[i] - '0') - (B[j] - '0'));
            --A[i + 1]
        } else {
            R.push_back();
        }
    }
}
#endif
