#if !defined(DEF_VEHICULE)
#define DEF_VEHICULE

class Vehicule
{
protected:
    int max_speed,kilometrage;
public:
    Vehicule(int max_speed = 240, int kilometrage = 0) : max_speed(max_speed), kilometrage(kilometrage) {}
    ~Vehicule() {}
    void setMax_speed(int max_speed);
    void setkilometrage(int kilometrage);
    int getMax_speed() const;
    int getKilometrage() const;
};

#endif // DEF_VEHICULE
