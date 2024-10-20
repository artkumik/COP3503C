#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "extrafile.h"

using namespace std;

int main()
{
	cout << "Which file(s) to open?\n";
	cout << "1. friendlyships.shp" << endl;
	cout << "2. enemyships.shp" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;


  vector<char*> buffers;

  vector<string> names;
  vector<string> classes;
  vector<short> length;
  vector<int> shield;
  vector<float> warp;

  vector<int> weaponcounts;
    
  vector<string> weaponnames;
  vector<int> weaponpowers;
  vector<float> weaponconsums;
  vector<int> firepowers;

  int offset;
  int firepower;

  string result;

  if(option == 1){
    ifstream file("friendlyships.shp",ios_base::binary);
    
    int shipCount;
    file.read((char*)&shipCount, 4);

    //general need
    
    
    for(int i = 0; i < shipCount; i += 1){
      int namelength;
      file.read((char*)&namelength, 4);

      //read name of length namelength
      char* namebuffer = new char[namelength];
      file.read(namebuffer, namelength);
      result = namebuffer;
      delete[] namebuffer;
      names.push_back(result);

      int classlength;
      file.read((char*)&classlength, 4);

      //read name of length namelength
      char* classbuffer = new char[classlength];
      file.read(classbuffer, classlength);
      result = classbuffer;
      delete[] classbuffer;
      classes.push_back(result);

      short currlength;
      file.read((char*)&currlength, 2);
      length.push_back(currlength);

      int currshield;
      file.read((char*)&currshield, 4);
      shield.push_back(currshield);

      float currwarp;
      file.read((char*)&currwarp, 4);
      warp.push_back(currwarp);

      int weaponcount;
      file.read((char*)&weaponcount, 4);
      weaponcounts.push_back(weaponcount);
      
      firepower = 0;
      
      if (weaponcount > 0){
        

        offset = buffers.size();

        for(int weapon = 0; weapon < weaponcount; weapon += 1){
          int weaponnamelength;
          file.read((char*)&weaponnamelength, 4);

          //read name of length namelength
          buffers.push_back(new char[weaponnamelength]);
          file.read(buffers[weapon + offset], weaponnamelength);
          result = buffers[weapon + offset];
          weaponnames.push_back(result);
          

          int weaponpower;
          file.read((char*)&weaponpower, 4);
          firepower += weaponpower;
          weaponpowers.push_back(weaponpower);

          float weaponconsum;
          file.read((char*)&weaponconsum, 4);
          weaponconsums.push_back(weaponconsum);
        }

      }
      firepowers.push_back(firepower);
    }

    file.close();
  }


  else if(option == 2){
    ifstream file("enemyships.shp",ios_base::binary);
    
    int shipCount;
    file.read((char*)&shipCount, 4);

    
    for(int i = 0; i < shipCount; i += 1){
      int namelength;
      file.read((char*)&namelength, 4);

      //read name of length namelength
      char* namebuffer = new char[namelength];
      file.read(namebuffer, namelength);
      result = namebuffer;
      delete[] namebuffer;
      names.push_back(result);

      int classlength;
      file.read((char*)&classlength, 4);

      //read name of length namelength
      char* classbuffer = new char[classlength];
      file.read(classbuffer, classlength);
      result = classbuffer;
      delete[] classbuffer;
      classes.push_back(result);

      short currlength;
      file.read((char*)&currlength, 2);
      length.push_back(currlength);

      int currshield;
      file.read((char*)&currshield, 4);
      shield.push_back(currshield);

      float currwarp;
      file.read((char*)&currwarp, 4);
      warp.push_back(currwarp);

      int weaponcount;
      file.read((char*)&weaponcount, 4);
      weaponcounts.push_back(weaponcount);
      
      firepower = 0;
      
      if (weaponcount > 0){
        

        offset = buffers.size();

        for(int weapon = 0; weapon < weaponcount; weapon += 1){
          int weaponnamelength;
          file.read((char*)&weaponnamelength, 4);

          //read name of length namelength
          buffers.push_back(new char[weaponnamelength]);
          file.read(buffers[weapon + offset], weaponnamelength);
          result = buffers[weapon + offset];
          weaponnames.push_back(result);
          

          int weaponpower;
          file.read((char*)&weaponpower, 4);
          firepower += weaponpower;
          weaponpowers.push_back(weaponpower);

          float weaponconsum;
          file.read((char*)&weaponconsum, 4);
          weaponconsums.push_back(weaponconsum);
        }

      }
      firepowers.push_back(firepower);
    }

    file.close();
  }


  else if(option == 3){
    ifstream file("friendlyships.shp",ios_base::binary);
    
    int shipCount;
    file.read((char*)&shipCount, 4);

    
    for(int i = 0; i < shipCount; i += 1){
      int namelength;
      file.read((char*)&namelength, 4);

      //read name of length namelength
      char* namebuffer = new char[namelength];
      file.read(namebuffer, namelength);
      result = namebuffer;
      delete[] namebuffer;
      names.push_back(result);

      int classlength;
      file.read((char*)&classlength, 4);

      //read name of length namelength
      char* classbuffer = new char[classlength];
      file.read(classbuffer, classlength);
      result = classbuffer;
      delete[] classbuffer;
      classes.push_back(result);

      short currlength;
      file.read((char*)&currlength, 2);
      length.push_back(currlength);

      int currshield;
      file.read((char*)&currshield, 4);
      shield.push_back(currshield);

      float currwarp;
      file.read((char*)&currwarp, 4);
      warp.push_back(currwarp);

      int weaponcount;
      file.read((char*)&weaponcount, 4);
      weaponcounts.push_back(weaponcount);
      
      firepower = 0;
      
      if (weaponcount > 0){
        

        offset = buffers.size();

        for(int weapon = 0; weapon < weaponcount; weapon += 1){
          int weaponnamelength;
          file.read((char*)&weaponnamelength, 4);

          //read name of length namelength
          buffers.push_back(new char[weaponnamelength]);
          file.read(buffers[weapon + offset], weaponnamelength);
          result = buffers[weapon + offset];
          weaponnames.push_back(result);
          

          int weaponpower;
          file.read((char*)&weaponpower, 4);
          firepower += weaponpower;
          weaponpowers.push_back(weaponpower);

          float weaponconsum;
          file.read((char*)&weaponconsum, 4);
          weaponconsums.push_back(weaponconsum);
        }

      }
      firepowers.push_back(firepower);
    }

    file.close();

    ifstream file2("enemyships.shp",ios_base::binary);
    
    int shipCount2;
    file2.read((char*)&shipCount2, 4);

    
    for(int i = 0; i < shipCount2; i += 1){
      int namelength;
      file2.read((char*)&namelength, 4);

      //read name of length namelength
      char* namebuffer = new char[namelength];
      file2.read(namebuffer, namelength);
      result = namebuffer;
      delete[] namebuffer;
      names.push_back(result);

      int classlength;
      file2.read((char*)&classlength, 4);

      //read name of length namelength
      char* classbuffer = new char[classlength];
      file2.read(classbuffer, classlength);
      result = classbuffer;
      delete[] classbuffer;
      classes.push_back(result);

      short currlength;
      file2.read((char*)&currlength, 2);
      length.push_back(currlength);

      int currshield;
      file2.read((char*)&currshield, 4);
      shield.push_back(currshield);

      float currwarp;
      file2.read((char*)&currwarp, 4);
      warp.push_back(currwarp);

      int weaponcount;
      file2.read((char*)&weaponcount, 4);
      weaponcounts.push_back(weaponcount);
      
      firepower = 0;
      
      if (weaponcount > 0){
        

        offset = buffers.size();

        for(int weapon = 0; weapon < weaponcount; weapon += 1){
          int weaponnamelength;
          file2.read((char*)&weaponnamelength, 4);

          //read name of length namelength
          buffers.push_back(new char[weaponnamelength]);
          file2.read(buffers[weapon + offset], weaponnamelength);
          result = buffers[weapon + offset];
          weaponnames.push_back(result);
          

          int weaponpower;
          file2.read((char*)&weaponpower, 4);
          firepower += weaponpower;
          weaponpowers.push_back(weaponpower);

          float weaponconsum;
          file2.read((char*)&weaponconsum, 4);
          weaponconsums.push_back(weaponconsum);
        }

      }
      firepowers.push_back(firepower);
    }

    file2.close();
  }

	cout << "1. Print all ships" << endl;
	cout << "2. Starship with the strongest weapon" << endl;
	cout << "3. Strongest starship overall" << endl;
	cout << "4. Weakest ship (ignoring unarmed)" << endl;
	cout << "5. Unarmed ships" << endl;
	
	cin >> option;

  if(option == 1){
    offset = 0;
    for(int i = 0; i < names.size();i+=1){
      cout << "Name: " << names[i] << endl;
      cout << "Class: " << classes[i] << endl;
      cout << "Length: " << length[i] << endl;
      cout << "Shield capacity: " << shield[i] << endl;
      cout << "Maximum Warp: " << warp[i] << endl;
      cout << "Armaments: " << endl;
      if(weaponcounts[i] == 0){
        cout << "Unarmed" << endl;
      }
      else{
        for(int j = 0; j < weaponcounts[i]; j += 1){
          cout << weaponnames[j+offset] << ", " << weaponpowers[j+offset] << ", " << weaponconsums[j+offset] << endl;
        }
        cout << "Total firepower: " << firepowers[i] << "\n" << endl;
      }

      offset += weaponcounts[i];
      

    }
  }
  else if(option == 2){
    int maxWeapon = 0;
    int maxWeaponPos;

    offset = 0;
    for(int i = 0; i < names.size();i+=1){
      for(int j = 0; j < weaponcounts[i]; j += 1){
        if(weaponpowers[j+offset]>maxWeapon){
          maxWeapon = weaponpowers[j+offset];
          maxWeaponPos = i;
        }
      }
      offset += weaponcounts[i];
    }

    offset = 0;

    for(int i = 0; i < maxWeaponPos; i += 1){
      offset += weaponcounts[i];
    }

    cout << "Name: " << names[maxWeaponPos] << endl;
    cout << "Class: " << classes[maxWeaponPos] << endl;
    cout << "Length: " << length[maxWeaponPos] << endl;
    cout << "Shield capacity: " << shield[maxWeaponPos] << endl;
    cout << "Maximum Warp: " << warp[maxWeaponPos] << endl;
    cout << "Armaments: " << endl;
    if(weaponcounts[maxWeaponPos] == 0){
      cout << "Unarmed" << endl;
    }
    else{
      for(int j = 0; j < weaponcounts[maxWeaponPos]; j += 1){
        cout << weaponnames[j+offset] << ", " << weaponpowers[j+offset] << ", " << weaponconsums[j+offset] << endl;
      }
      cout << "Total firepower: " << firepowers[maxWeaponPos] << "\n" << endl;
    }
    

  }
  else if(option == 3){
    int maxFirepower = 0;
    int maxFirepowerPos;
    for(int i = 0; i < firepowers.size(); i += 1){
      if(firepowers[i] > maxFirepower){
        maxFirepower = firepowers[i];
        maxFirepowerPos = i;
      }
    }

    offset = 0;

    for(int i = 0; i < maxFirepowerPos; i += 1){
      offset += weaponcounts[i];
    }

    cout << "Name: " << names[maxFirepowerPos] << endl;
    cout << "Class: " << classes[maxFirepowerPos] << endl;
    cout << "Length: " << length[maxFirepowerPos] << endl;
    cout << "Shield capacity: " << shield[maxFirepowerPos] << endl;
    cout << "Maximum Warp: " << warp[maxFirepowerPos] << endl;
    cout << "Armaments: " << endl;
    if(weaponcounts[maxFirepowerPos] == 0){
      cout << "Unarmed" << endl;
    }
    else{
      for(int j = 0; j < weaponcounts[maxFirepowerPos]; j += 1){
        cout << weaponnames[j+offset] << ", " << weaponpowers[j+offset] << ", " << weaponconsums[j+offset] << endl;
      }
      cout << "Total firepower: " << firepowers[maxFirepowerPos] << "\n" << endl;
    }

  }
  else if(option == 4){
    int minFirepower = 1000;
    int minFirepowerPos;
    for(int i = 0; i < firepowers.size(); i += 1){
      if(firepowers[i] < minFirepower and firepowers[i] > 0){
        minFirepower = firepowers[i];
        minFirepowerPos = i;
      }
    }

    offset = 0;

    for(int i = 0; i < minFirepowerPos; i += 1){
      offset += weaponcounts[i];
    }

    cout << "Name: " << names[minFirepowerPos] << endl;
    cout << "Class: " << classes[minFirepowerPos] << endl;
    cout << "Length: " << length[minFirepowerPos] << endl;
    cout << "Shield capacity: " << shield[minFirepowerPos] << endl;
    cout << "Maximum Warp: " << warp[minFirepowerPos] << endl;
    cout << "Armaments: " << endl;
    if(weaponcounts[minFirepowerPos] == 0){
      cout << "Unarmed" << endl;
    }
    else{
      for(int j = 0; j < weaponcounts[minFirepowerPos]; j += 1){
        cout << weaponnames[j+offset] << ", " << weaponpowers[j+offset] << ", " << weaponconsums[j+offset] << endl;
      }
      cout << "Total firepower: " << firepowers[minFirepowerPos] << "\n" << endl;
    }
  }
	else if(option == 5){
    offset = 0;

    for(int i = 0; i < names.size();i+=1){
      if(weaponcounts[i] == 0){
        cout << "Name: " << names[i] << endl;
        cout << "Class: " << classes[i] << endl;
        cout << "Length: " << length[i] << endl;
        cout << "Shield capacity: " << shield[i] << endl;
        cout << "Maximum Warp: " << warp[i] << endl;
        cout << "Armaments: " << endl;
        cout << "Unarmed" << endl;
      }
    }
  }

	
	
   return 0;
}