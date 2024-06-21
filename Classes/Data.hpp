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
    ~DATA();
    void setInserirdia();
    void setInserirhora();
    void setInserirmes();
    void setInserirano();
    void setInserirminutos();
    void setModificarrdia();
    void setModificarrhora();
    void setModificarrmes();
    void setModificarrano();
    void setModificarrminutos();
    int getverdia();
    int getverhora();
    int getvermes();
    int getverano();
    int getverminutos();

} ;
#endif 





