#include<iostream>
using namespace std;

class Dimension {


    private: 
	    int height;
      int width;
      int depth;

    public: 
	    Dimension(int h, int w, int d) 
      {
        height = h;
        width = w;
        depth = d;
      }

      int getHeight() 
      {
        return height;
      }

      void setHeight(int height) 
      {
        this->height = height;
      }

      int getWidth() 
      {
        return width;
      }

      void setWidth(int width) 
      {
        this->width = width;
      }

      int getDepth() 
      {
        return depth;
      }

      void setDepth(int depth) 
      {
        this->depth = depth;
      }
};

class Resolution {
    private:  
	int width;
    int height;


    public:
	 Resolution(int w, int h) {
         width = w;
         height = h;
    }
    int getWidth() {
        return width;
    }

    void setWidth(int width) {
        this->width = width;
    }
	
	int getHeight() {
        return height;
    }

      void setHeight(int height) {
        this->height = height;
    }
};

class Case {

    private:
	 string model;
     string manufacturer;
     string powerSupply;
     Dimension *dimensions;


     public:
	
	Case(string m, string ma, string p, Dimension *d) 
	{
         model = m;
         manufacturer = ma;
         powerSupply = p;
         dimensions = d;
    }

  void pressPowerbutton()
    {

        cout<<"Power button pressed";
    }
     
	 string getModel() {
        return model;
    }

    void setModel(string model) {
        this->model = model;
    }

    string getManufacturer() {
        return manufacturer;
    }

    void setManufacturer(string manufacturer) {
        this->manufacturer = manufacturer;
    }

    string getPowerSupply() {
        return powerSupply;
    }

    void setPowerSupply(string powerSupply) {
        this->powerSupply = powerSupply;
    }

 void setDimensions(Dimension *dimensions) {
        this->dimensions = dimensions;
    }
    void getDimensions() {
         cout<<dimensions;
    }
};
class Monitor {

    private:
	string model;
    string manufacturer;
    int size;
    Resolution *nativeResolution;

     public:
	Monitor(string m, string ma, int s, Resolution *r) {
         model = m;
         manufacturer = ma;
         size = s;
         nativeResolution = r;
    }
      string getModel() {
        return model;
    }

      void setModel(string model) {
        this->model = model;
    }

      string getManufacturer() {
        return manufacturer;
    }

      void setManufacturer(string manufacturer) {
        this->manufacturer = manufacturer;
    }

      int getSize() {
        return size;
    }

      void setSize(int size) {
        this->size = size;
    }

      void getNativeResolution() {
         cout<<nativeResolution;
    }

      void setNativeResolution(Resolution *nativeResolution) {
        this->nativeResolution = nativeResolution;
    }
};
    class Motherboard {

    private:
	string model;
    string manufacturer;
    int ramSlots;
    int cardSlots;
    string bios;


     public:
	Motherboard(string m, string ma, int r, int c, string b) {
         model = m;
         manufacturer = ma;
         ramSlots = r;
         cardSlots = c;
         bios = b;
    }

    void LoadPRogram(string program)
    {

        cout<<"Program now loading";
    }
      string getModel() {
        return model;
    }

      void setModel(string model) {
        this->model = model;
    }

      string getManufacturer() {
        return manufacturer;
    }

      void setManufacturer(string manufacturer) {
        this->manufacturer = manufacturer;
    }

      int getRamSlots() {
        return ramSlots;
    }

      void setRamSlots(int ramSlots) {
        this->ramSlots = ramSlots;
    }

      int getCardSlots() {
        return cardSlots;
    }

      void setCardSlots(int cardSlots) {
        this->cardSlots = cardSlots;
    }

      string getBios() {
        return bios;
    }

      void setBios(string bios) {
        this->bios = bios;
    }
};

class PC {


    private:
	Case *theCase;
    Monitor *monitor;
    Motherboard *motherboard;
	
	 public:
	 PC (Case *c, Monitor *m, Motherboard *mb)
	{
		 theCase=c;
		 monitor=m;
		 motherboard=mb;
	}	
	
	void LoadProgram()
	{
		cout<<"Program loading";
	}
	
        Case getCase() {
        return theCase;
    }

      void setCase(Case  theCase) {
        this->theCase = theCase;
    }
	  Motherboard getMotherboard() {
        return motherboard;
    }

      void setMotherboard(Motherboard  motherboard) {
        this->motherboard = motherboard;
    }
};

int main() {
	
	Dimension d(11,12,13);
    
	Case theCase("ab124","dell","on",&d);
	
    Motherboard motherboard("12EF","hp",4,2,"v2.04");

    Resolution r(14,12);
    Monitor  monitor("12WE","accer",14,&r);

    PC thePC(&theCase,&monitor,&motherboard);
	thePC.display();
    thePC.LoadProgram();



return 0;

}