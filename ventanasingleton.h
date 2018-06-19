#ifndef VENTANASINGLETON_H
#define VENTANASINGLETON_H

class VentanaSingleton
{
    int bin1;
    int bin2;
    int bin3;
    int bin4;
    int bin5;
    int bin6;
    int bin7;
    int bin8;
    int bin9;
    int bin10;

    bool reverbActivo;
    bool barrasActivas;

    static VentanaSingleton *s_instance;
    VentanaSingleton(int bin1n=1, int bin2n=1, int bin3n=1, int bin4n=1, int bin5n=1, int bin6n=1, int bin7n=1, int bin8n=1, int bin9n=1, int bin10n=1)
    {
        bin1 = bin1n;
        bin2 = bin2n;
        bin3 = bin3n;
        bin4 = bin4n;
        bin5 = bin5n;
        bin6 = bin6n;
        bin7 = bin7n;
        bin8 = bin8n;
        bin9 = bin9n;
        bin10 = bin10n;
    }
  public:
    int getBin1()
    {
        return bin1;
    }
    void setBin1(int v)
    {
        bin1 = v;
    }
    int getBin2()
    {
        return bin2;
    }
    void setBin2(int v)
    {
        bin2 = v;
    }
    int getBin3()
    {
        return bin3;
    }
    void setBin3(int v)
    {
        bin3 = v;
    }
    int getBin4()
    {
        return bin4;
    }
    void setBin4(int v)
    {
        bin4 = v;
    }
    int getBin5()
    {
        return bin5;
    }
    void setBin5(int v)
    {
        bin5 = v;
    }
    int getBin6()
    {
        return bin6;
    }
    void setBin6(int v)
    {
        bin6 = v;
    }
    int getBin7()
    {
        return bin7;
    }
    void setBin7(int v)
    {
        bin7 = v;
    }
    int getBin8()
    {
        return bin8;
    }
    void setBin8(int v)
    {
        bin8 = v;
    }
    int getBin9()
    {
        return bin9;
    }
    void setBin9(int v)
    {
        bin9 = v;
    }
    int getBin10()
    {
        return bin10;
    }
    void setBin10(int v)
    {
        bin10 = v;
    }

    bool getReverbActivo()
    {
        return reverbActivo;
    }

    void setReverbActivo(bool value)
    {
        reverbActivo = value;
    }

    bool getBarrasActivo()
    {
        return barrasActivas;
    }

    void setBarrasActivo(bool value)
    {
        barrasActivas = value;
    }

    static VentanaSingleton *instance()
    {
        if (!s_instance)
          s_instance = new VentanaSingleton;
        return s_instance;
    }
};

#endif // VENTANASINGLETON_H
