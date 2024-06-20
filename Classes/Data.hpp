#ifndef Data_H
#define Data_H

class DATA {
    private:
    int dia;
    int mes;
    int ano;
    int horas;
    int minutos;
    public:
    DATA(int d,int m ,int a ,int h ,int mn ) :dia(d) ,mes(m) ,ano(a),horas(h),minutos(mn){}
    void Inserirdata();
    void Modificardata();
} ;
#endif 





