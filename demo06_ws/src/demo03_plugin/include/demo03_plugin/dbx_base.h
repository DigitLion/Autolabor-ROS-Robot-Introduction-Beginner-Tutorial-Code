#ifndef DBX_BASE_H_
#define DBX_BASE_H_

namespace dbx_base_ns
{
    /* 
        注意：必须保证基类中包含无参数构造
     */

    class Dbx_Base
    {
        protected:
            Dbx_Base(){}
        private:
            /* data */
        public:
            //计算周长的函数
            virtual double getlength() = 0;
            //初始化边长的函数
            virtual void init(double sid_length) = 0;
    
    };

} 


#endif