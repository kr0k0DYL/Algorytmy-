#include <iostream>
#include <vector>
#include <cassert>

//Ta funkcja sortuje nam tablicę przez początkowe k i które zmieniają miejsce liczbą
int dzielenie(std::vector<int> & tablica, int start, int koniec) {
  int schowek, pivot;
  pivot = tablica[koniec];
  int k=-1; // k to jest nasza komórka przed i, która jest do sortowania elementów
  for (int i = 0; i < tablica.size(); i++) {
    if (tablica[i] < pivot) {
      k = k + 1;
      schowek = tablica[k];
      tablica[k] = tablica[i];
      tablica[i] = schowek;
    }
  }
  k = k + 1;
  schowek = tablica[k];
  tablica[k] = pivot;
  tablica[koniec] = schowek;
  return k;
}


// Ta fukncja wywołuje się i dzieli nam tablicę
void quick_sort(std::vector<int> & tablica, int początek, int koniec) {
  if (koniec <= początek) return;// zwracamy najprostszy przypadek dla rekursji
  else {
  int pivot =  dzielenie(tablica, początek, koniec);
     quick_sort( tablica, pivot + 1, koniec);
  quick_sort( tablica, początek, pivot - 1);
    
    }
}

void wypisywanie(std::vector<int> tablica){
   for (int i = 0; i < tablica.size(); i++) {
    std::cout << tablica[i];
  }
}
  /*
      quisort ([4,2,1,6], 0, 3)
      dzielenie ([4,2,1,6, 0 ,3]) piwot = 6
      
  
  */
void testowanie(){
   std::vector<int> tablica = {4, 2, 1, 6};
 std::vector <int> oczekiwany_wynik = {1, 2, 4, 6};
 quick_sort(tablica, 0, 3);
assert(tablica == oczekiwany_wynik);
 
  // ASSERT DLA FUNKCJI DZIELENIE

   std::vector<int> tablica1 = {4, 2, 1, 6};
  int wynik1 = dzielenie(tablica1, 0, 3);
  assert(wynik1 == 3);
  assert(tablica[3] == 6);
    std::vector<int> tablica2 = {6, 2, 8, 1};
  std::vector <int> oczekiwany_wynik2 = {1, 2, 8, 6};
  dzielenie(tablica2,0,3);
  assert(tablica2 == oczekiwany_wynik2);
}
int main() {
  std::vector<int> tablica = {4, 2, 1, 6};
  
  // Ta fukncja będzie wykonywała się cały czas i dzieliła naszą tablicę;
  quick_sort(tablica, 0, tablica.size() - 1);
  wypisywanie(tablica);
  //assert(quick_sort(4 2, 0, 1)) == 2 4);
  testowanie();
}
