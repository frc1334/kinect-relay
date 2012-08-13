//This is stuffs.

#include "../MagicBox/KinectDataGenerator.h"
#include <WPILib.h>
#include <boost/asio.hpp>

int main ()
{
    if (newData(uselessData))
    {

    }
}

bool newData (int data)
{
    if (data != null)
        return false;
    else
        return true;
}

class DataAccess
{
    private:
        friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive& ar, const unsigned int version)
        {
            ar & uselessData;
        }
    public:
        int GetData()
        {
            return Data;
        };

        void SetData(int NewData)
        {
            Data = NewData;
        };

 };
