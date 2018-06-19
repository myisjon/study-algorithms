#include "iostream"
#include "memory.h"

using namespace std;

class CArray {
    private:
        int size;
        int *ptr;

    public:
        CArray(int s=0);
        CArray(const CArray &a);
        ~CArray();
        void push(int v);
        char *show();
        int length();

        CArray &operator = (const CArray & a);
        int &operator [] (int i);
};


CArray::CArray(int s) : size(s)
{
    if (s == 0)
    {
        ptr = NULL;
    }
    else
    {
        ptr = new int[size];
    }
}

CArray::CArray(const CArray &a): size(a.size)
{
    if (!a.ptr)
    {
        ptr = NULL;
        return ;
    }
    ptr = new int [size];
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
}

CArray::~CArray()
{
    if (ptr)
    {
        delete []ptr;
    }
}

void CArray::push(int v)
{
    if (!ptr)
    {
        ptr = new int[1];
    }
    else
    {
        int * tmp_ptr = new int[size + 1];
        memcpy(tmp_ptr, ptr, sizeof(int) * size);
        delete [] ptr;
        ptr = tmp_ptr;
    }

    ptr[size++] = v;

}

char *CArray::show()
{
    if (ptr)
    {
       int total_char_size = 0;
       for (int i = 0; i < size; i++)
       {
            int temp = ptr[i];
            if (temp < 10 && temp > -1)
            {
                total_char_size++;
                continue;
            }
            if (temp < 0)
            {
                total_char_size++;
                temp = 0 - temp;
            }
            while (temp != 0)
            {
                temp /= 10;
                total_char_size++;
            }

       }
       char * temp_s_ptr = new char[2 * total_char_size];
       memset(temp_s_ptr, 0, sizeof(char) * 2 * total_char_size);
       char * t_s = new char[10];
       int t_i = 0;
       total_char_size = 0;
       for (int i = 0; i < size; i++)
       {
            int temp = ptr[i];
            if (temp < 0)
            {
                temp_s_ptr[total_char_size++] = '-';
                temp = 0 - temp;
            }
            else if (temp == 0)
            {
                temp_s_ptr[total_char_size++] = '0';
                temp_s_ptr[total_char_size++] = 32;
                continue;
            }
            t_i = 0;
            while (temp != 0)
            {
                t_s[t_i++] = 48 + temp % 10;
                temp /= 10;
            }
            for (int j = t_i - 1; j >= 0; j--)
            {
                temp_s_ptr[total_char_size++] = t_s[j];
                t_s[j] = 0;
            }
            temp_s_ptr[total_char_size++] = 32;
       }
       // cout << total_char_size << endl;
       delete []t_s;
       return temp_s_ptr;
    }
    return NULL;
}

int CArray::length()
{
    return size;
}

CArray &CArray::operator = (const CArray &a)
{
    if (ptr == a.ptr)
    {
        return * this;
    }
    if (a.ptr == NULL)
    {
        if (ptr)
        {
            delete []ptr;
        }
        ptr = NULL;
        size = 0;
        return *this;
    }

    if (a.size > size)
    {
        if (ptr)
        {
            delete []ptr;
        }
        ptr = new int[a.size];
    }
    size = a.size;
    memcpy(ptr, a.ptr, sizeof(int) * size);
    return *this;
}

int &CArray::operator [](int i)
{
    return ptr[i];
}

int main()
{
    CArray a1;

    cout << "======== init array a1 ========" << endl;
    for (int i = 0; i < 10; i++)
    {
        a1.push(i * i * ( i % 2 > 0? -1: 1));
    }
    cout << "output a1: \n" << a1.show() << endl;

    CArray a2, a3;
    // copy a1 value to a2
   cout << "===== copy a1 value to a2 ========" << endl;
   a2 = a1;
   cout << "output a2: \n" << a2.show() << endl;
   cout << "output a2 length: " << a2.length() << endl;
   // set a2 to null
   a2 = a3;
   cout << "output a2 length: " << a2.length() << endl;

   cout << "======== update a1 value ========" << endl;
   for (int i = 0; i < a1.length(); i++)
   {
       a1[i] = a1[i] + 1;
   }
   cout << "output a1: \n" << a1.show() << endl;

   // use copy constructor set a4 to a1 value
   CArray a4(a1);
   cout << "output init a4: \n" << a4.show() << endl;
   return 0;
}
