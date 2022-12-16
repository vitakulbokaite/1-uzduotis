# 2-uzduotis

* Pakeista pirmoje užduotyje naudotas struct Studentas į bazinę klasę Žmogus ir išvestinę klasę Studentas
* Duomenų rūšiavimo ir išvedimo analizė

Naudojant struct:

|     | **1000** | **10000** | **100000** | **1000000** |
| --- | --- | --- | --- | --- |
| Failo rūšiavimas | 0.0097143 s | 0.0833837 s | 1.01316 s | 12.6888 s |
| Išvedimas | 0.0227488 s | 0.166639 s | 1.81583 s | 17.9612 s |
| **Iš viso** | **0.0324631 s** | **0.2500227 s** | **2.82899 s** | **30.65 s** |

Naudojant class:

|     | **1000** | **10000** | **100000** | **1000000** |
| --- | --- | --- | --- | --- |
| Failo rūšiavimas | 0.0005376 s | 0.0044596 s | 0.0427472 s | 0.407435 s |
| Išvedimas | 0.0254936 s | 0.196903 s | 1.70857 s | 16.7381 s |
| **Iš viso** | **0.0260312 s** | **0.2013626 s** | **1.7513172 s** | **17.145535 s** |

* Realizuota *Rule of three* ir palyginimo operatoriai
* Dokumentacija naudojant *Doxygen*
