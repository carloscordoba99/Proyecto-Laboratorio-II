#ifndef REPARACIONES_H_INCLUDED
#define REPARACIONES_H_INCLUDED


class Reparaciones
{
private:
    int dni_cliente;
    int precio;
    Fecha fecha_ingreso;
    bool activo;
public:
    bool cargar();
    void mostrar();
    int get_dnicliente()
    {
        return dni_cliente;
    }
    int get_precio()
    {
        return precio;
    }
    Fecha get_fechaingreso()
    {
        return fecha_ingreso;
    }

    void set_dnicliente(int d)
    {
        dni_cliente=d;
    }
    void set_precio(int p)
    {
        precio=p;
    }
    void set_fechaingreso(Fecha fi)
    {
        fecha_ingreso=fi;
    }
    void set_activo(bool a)
    {
        activo=a;
    }
    bool get_activo()
    {
        return activo;
    }
    bool Modificar_de_disco(int);
    bool Grabar_en_disco();
    bool Leer_de_disco(int);
    void Modificar_fecha(int dia,int mes,int anio);
};


bool Reparaciones::cargar()
{
    system("cls");
    int encontro;
    int dia,mes,anio;
    cout << "INGRESAR DNI CLIENTE: " << endl;
    cin >> dni_cliente;
    encontro=buscar_dni(dni_cliente);
    if(encontro!=-1)
    {
        cout << "INGRESAR PRECIO: " << endl;
        cin >> precio;
        cout << "INGRESAR FECHA INGRESO (D/M/A): " << endl;
        cin>>dia;
        cin>>mes;
        cin>>anio;
        fecha_ingreso.setDia(dia);
        fecha_ingreso.setMes(mes);
        fecha_ingreso.setAnio(anio);
        activo=true;
    }
    else
    {
        return false;
    }
    return true;
}

void Reparaciones::mostrar()
{
    system("cls");
    cout << "DNI CLIENTE: " << endl;
    cout << dni_cliente << endl;
    cout << "PRECIO: " << endl;
    cout << precio << endl;
    cout << "FECHA INGRESO (D/M/A): " << endl;
    cout << fecha_ingreso.getDia() << endl;
    cout << fecha_ingreso.getMes() << endl;
    cout << fecha_ingreso.getAnio() << endl;
}


bool Reparaciones::Modificar_de_disco(int pos)
{
    bool listo;
    FILE *p;
    p=fopen("reparaciones.dat","rb+");
    if(p==NULL)
        return false;
    fseek(p,sizeof (Reparaciones)*pos,0);
    listo=fwrite(this,sizeof (Reparaciones),1,p);
    fclose(p);
    return listo;
}


bool Reparaciones::Grabar_en_disco()
{
    FILE *p;
    p=fopen("reparaciones.dat","ab");
    if(p==NULL)
        return false;
    bool escribio=fwrite(this,sizeof (Reparaciones),1,p);
    fclose(p);
    return escribio;
}

bool Reparaciones::Leer_de_disco(int pos)
{
    Reparaciones reg;
    FILE *p;
    p=fopen("reparaciones.dat","rb");
    if(p==NULL)
        return false;
    fseek(p,sizeof (Reparaciones)*pos,0);
    bool leyo=fread(this,sizeof (Reparaciones),1,p); ///tambien puede ser sizeof *this (peso de lo que apunta el puntero).
    fclose(p);
    return leyo;
}

void Reparaciones::Modificar_fecha(int dia,int mes,int anio)
{
    fecha_ingreso.setDia(dia);
    fecha_ingreso.setMes(mes);
    fecha_ingreso.setAnio(anio);
}

//******************************************************
//FUNCIONES EXTERNAS

bool leer_reparaciones()
{
    Reparaciones reg;
    int pos=0;
    while(reg.Leer_de_disco(pos)==true)
    {
        if(reg.get_activo()==true)
        {
            reg.mostrar();
            system("pause");
        }
        pos++;
    }
    return true;
}

void baja_reparaciones()
{
    int pos,dni;
    Reparaciones reg;
    cout << "ingresar dni. cliente: " << endl;
    cin >> dni;
    pos=buscar_dni(dni);
    if(pos==-1)
    {
        cout << "no se encuentra el cliente registrado. " << endl;
        system("pause");
        return;
    }
    pos=buscar_dni_reparaciones(dni);
    if(pos!=-1){
        if(reg.Leer_de_disco(pos)==true){
            reg.set_activo(false);
                if(reg.Modificar_de_disco(pos)==false){
                    cout << "no se pudo dar de baja. " << endl;
                    return;
                }
                else{
                    cout << "el articulo se dio de baja. " << endl;
                    system("pause");

                }
        }
    }
    else{
        cout << "no se encuentra dni en archivo reparaciones. " << endl;
        system("pause");
        return;
    }

}

void alta_reparaciones()
{
    Reparaciones reg;
    system("cls");
    if(reg.cargar()==true)
    {
        if(reg.Grabar_en_disco()==true)
        {
            cout << "la reparacion se grabo con exito. " << endl;
            system("pause>null");
        }
    }
    else
    {
        cout<<"No existe el cliente. " << endl;
        cout<<"Presione una tecla para continuar. " << endl;
        system("pause>null");

    }
}


int buscar_dni_reparaciones(int dni)
{
    int pos=0;
    Reparaciones reg;
    while(reg.Leer_de_disco(pos)==true)
    {
        if(reg.get_dnicliente()==dni)
        {
            return pos;
        }
        pos++;

    }
    return -1;
}



void busq_dni_rep()
{
    Reparaciones reg;
    int dni,pos;
    cout << "ingrese dni cliente: " << endl;
    cin >> dni;
    if(buscar_dni(dni)!=-1)
    {
        pos=0;
        while(reg.Leer_de_disco(pos)==true)
        {
            if(reg.get_dnicliente()==dni)
            {
                if(reg.get_activo()==true){
                    reg.mostrar();
                    system("pause");
                }
            }
        pos++;
        }
    }
    else
    {
        cout << "no existe el dni en archivo clientes! " << endl;
        system("pause");
    }
}

void busq_fecha_rep()
{
    Reparaciones reg;
    Fecha obj;
    int anio,mes,dia;
    int pos=0;
    cout << "ingresar fecha reparacion: (D/M/A)" << endl;
    cin >> dia;
    obj.setDia(dia);
    cin >> mes;
    obj.setMes(mes);
    cin >> anio;
    obj.setAnio(anio);
    bool bandera=false;
    while(reg.Leer_de_disco(pos)==true)
    {
        if(obj.NumeroSerie()==reg.get_fechaingreso().NumeroSerie())
        {
            bandera=true;
            if(reg.get_activo()==true){
                reg.mostrar();
                system("pause");
            }
        }
        pos++;
    }
    if(bandera==false)
    {
        cout << "no se registra reparaciones para esa fecha. " << endl;
        system("pause");
    }


}


void menu_reparaciones()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"Menu Reparaciones"<<endl;
        cout<<"1. Alta"<<endl;
        cout<<"2. baja"<<endl;
        cout<<"3. Modificacion"<<endl;
        cout<<"4. Listado"<<endl;
        cout<<"5. Reportes"<<endl;
        cout<<"0. Atras"<<endl;
        cout<<"Ingrese la opcion: "<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            alta_reparaciones();
            break;
        case 2:
            baja_reparaciones();
            break;
        case 3:
            Mod_reparaciones();
            break;
        case 4:
            bool b;
            b=leer_reparaciones();
            break;
        case 5:
            reportes_reparaciones();
            break;
        case 0:
            return ;
        default:
            cout<<"Opcion incorrecta. Presione una tecla para continuar";
            system("pause>null");
            break;
        }
    }

}

void reportes_reparaciones()
{
    int opc;
    while(true)
    {
        system("cls");
        cout<<"Reportes Reparaciones"<<endl;
        cout<<"1. busqueda por dni cliente"<<endl;
        cout<<"2. busqueda por fecha ingreso"<<endl;
        cout<<"0. Atras"<<endl;
        cout<<"Ingrese la opcion: "<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            busq_dni_rep();
            break;
        case 2:
            busq_fecha_rep();
            break;
        case 0:
            return ;
        default:
            cout<<"Opcion incorrecta. Presione una tecla para continuar";
            system("pause>null");
            break;
        }
    }

};

#endif // REPARACIONES_H_INCLUDED
