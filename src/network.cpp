#include "network.h"
#include "random.h"
#include <vector>
#include <stdexcept>
using namespace std;

#include <iostream>


void Network::resize(const size_t& n)
// gestion d'erreur dans simulation.cpp (si n<1)
{
  values.clear();
  values.resize(n);
  RNG.normal(values,0,1);
}

bool Network::add_link(const size_t& a, const size_t& b)
{
  if (a==b or a>=size() or b>=size() or a<0 or b<0)  return false;

  for (auto i : neighbors(a)) {
    if (i==b) return false;
  }
  for (auto j : neighbors(b)) {
    if (j==a) return false;
  }

  links.insert( { {a,b}, {b,a} } );
  return true;
}

            // VERSION 1
// 1ere conception : ne passe pas les tests.
size_t Network::random_connect(const double& mean_deg)
{
  if ( (mean_deg> size()-1) or mean_deg<1)  {
    throw invalid_argument ("Enter a positiv number smaller than the number of nodes minus 1.");
  }
  size_t res (0);
  links.clear();

  vector<int> poiss ( size() );
  RNG.poisson(poiss, mean_deg);

  vector <size_t> linked_nodes (size());
  for (size_t j = 0; j<linked_nodes.size(); ++j) {
    linked_nodes[j]=j;
  }

  for (int n=0; n<size() ; ++n) {
    RNG.shuffle(linked_nodes);

    size_t h (0);
    for (int i=degree(n); i<poiss[n] && h<linked_nodes.size(); ++h) {
      if (add_link(n, linked_nodes[h])) {res++; i++;}
    }
  }
  return res;
}



          // VERSION 2 :
// 2e conception. Passe les tests. 
/*
size_t Network::random_connect(const double& mean_deg)
{
  size_t res (0);
  links.clear();

  vector<int> poiss ( size() );
  RNG.poisson(poiss, mean_deg);

  vector <size_t> linked_nodes (size());
  for (size_t j = 0; j<linked_nodes.size(); ++j) {
    linked_nodes[j]=j;
  }

  for (int n=0; n<size() ; ++n) {
    RNG.shuffle(linked_nodes);

    size_t h (0);
    for (int i=0; i<poiss[n] && h<linked_nodes.size(); ++h) {
      if (add_link(n, linked_nodes[h])) {res++; i++;}
    }
  }
  return res;
}
*/


size_t Network::set_values(const std::vector<double>& tab_val){
  values.clear();
  values = tab_val;
  return tab_val.size();
}


size_t Network::size() const
{
  return values.size();
}

size_t Network::degree(const size_t & _n) const
{
  return links.count(_n);
}

double Network::value(const size_t & _n) const
{
  if ( _n>=size() or _n<0 ) {
    throw invalid_argument ("Acces hors du tableau values.");
  }
  else {return values[_n]; }
}

vector<double> Network::sorted_values() const
{
  vector<double> sorted_value (values);
  sort(sorted_value.begin(), sorted_value.end(), greater<double>());
  return sorted_value;
}

vector<size_t> Network::neighbors(const size_t& n) const
{
  vector<size_t> res (0);
  if (n>= 0 and n<size()) {
    auto range = links.equal_range(n);
    for (auto i = range.first; i != range.second; ++i) {
      res.push_back( i->second ) ;
    }
  }
  return res;
}
