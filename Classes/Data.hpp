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
    ~DATA()= default;
    void setInserirdia(int d);
    void setInserirhora(int d);
    void setInserirmes(int d);
    void setInserirano(int d);
    void setInserirminutos(int d);
    void setModificarrdia(int d);
    void setModificarrhora(int d);
    void setModificarrmes(int d);
    void setModificarrano(int d);
    void setModificarrminutos(int d);
    
    int getverdatas();
} ;
#endif 





