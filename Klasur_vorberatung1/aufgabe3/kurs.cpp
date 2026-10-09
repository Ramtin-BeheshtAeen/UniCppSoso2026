#include "kurs.h"
#include <algorithm>
#include <numeric>

// ===================== Student =====================

// TODO: Konstruktor (Initialisierungsliste verwenden)
Student::Student(std::string name, int matrikelnummer) : name_(name) , matrikelnummer_(matrikelnummer) {}

void Student::addNote(double note)
{
  noten_.push_back(note);
}

double Student::durchschnitt() const
{
    // TODO (a): std::accumulate
  double sum = std::accumulate(noten_.begin(), noten_.end(), 0.0);
  if(noten_.size() == 0) {return 0.0;}
  return sum / noten_.size();
}

const std::string& Student::getName() const
{
    return name_;
}

int Student::getMatrikelnummer() const
{
    
  return matrikelnummer_;
}

// ===================== Kurs =====================

Kurs::Kurs(std::string titel) : titel_(std::move(titel)) {}

void Kurs::hinzufuegen(std::unique_ptr<Student> student)
{
    // TODO: Achtung, unique_ptr kann man nicht kopieren!
    // teilnermer is vector of unique_pointers : vector<std::unique_ptr<Student>>
  teilnehmer_.push_back(move(student));
    
}

Student* Kurs::finde(int matrikelnummer) const
{
    // TODO
  for(const std::unique_ptr<Student>  &student : teilnehmer_){
    if( student->getMatrikelnummer() == matrikelnummer){
      return student.get(); //send back unique pointer's address
    }
  }
  return nullptr;
}

std::vector<std::string> Kurs::namen() const
{
  std::vector<std::string> ergebnis(teilnehmer_.size());
    // TODO (b): std::transform
  //std::transform(hello.cbegin(), hello.cend(), hello.begin(), to_uppercase);
  std::transform(teilnehmer_.cbegin(), teilnehmer_.cend(), ergebnis.begin(),[](const auto &s){return s->getName();});
  return ergebnis;
   
}

double Kurs::kursDurchschnitt() const
{
    // TODO (c): std::accumulate (Tipp: Lambda als 4. Argument)
  double sum = std::accumulate(teilnehmer_.begin(), teilnehmer_.end(), 0.0, [](double bisher, const auto &s){ return(s-> durchschnitt() + bisher);} );
  return sum / (teilnehmer_.size());
  
}

std::map<std::string, double> Kurs::uebersicht() const
{
  std::map<std::string, double> kurs;
  for(const auto &s : teilnehmer_){
    std::string name = s->getName();
    kurs[name] = s-> durchschnitt();
  }
  return kurs;
}

long Kurs::anzahlBestanden() const
{
    // TODO (e): std::count_if
   
}

std::size_t Kurs::anzahl() const
{
    return teilnehmer_.size();
}

const std::string& Kurs::getTitel() const
{
    return titel_;
}
