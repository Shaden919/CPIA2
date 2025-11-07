#if !defined(DEF_FRACTION)
#define DEF_FRACTION

class Fraction
{
private:
    int numerateur;
    int denominateur;
public:
    Fraction();
    Fraction(int numerateur, int denominateur);
    ~Fraction();
    void setNumerateur(int numerateur);
    void setDenominateur(int denominateur);
    void simplify();
    int getNumerateur();
    int getDenominateur();
    Fraction add(Fraction fraction) const;
    Fraction minus(Fraction fraction) const;
    Fraction multiply(Fraction fraction) const;
    Fraction divide(Fraction fraction);
};


#endif // DEF_FRACTION
