*This project has been created as part of the 42 curriculum by musipit*

# get_next_line

## İçerik

İşlev, bir dosya tanımlayıcısından okunan bir satır döndürür. Ardışık çağrılar ardışık satırları teker teker döndürür. Satır, dosyanın sonuna ulaşıldığı ve bir `\n` karakteriyle bitmediği durumlar haricinde, fonksiyondan dönen değer sonlandırıcı bir `\n` karakteriyle biten bir karakter dizisidir.

### Zorunlu Bölüm
* `get_next_line` fonksiyonunun bir dosya tanımlayıcısını okuyarak her çağrıda bir satır döndürmesi gereklidir.
* `BUFFER_SIZE` parametresi ile uyumlu çalışmalı ve hata durumlarını doğru şekilde ele almalıdır.

### Bonus Bölüm
* `get_next_line`, birden fazla dosya tanımlayıcısını (multi-file descriptor) aynı anda yönetebilmelidir.
* Her dosya tanımlayıcısı bağımsız bir şekilde ele alınmalı ve işlemler bir diğerini etkilememelidir.

### Kullanım

Kodunuza uygun başlıklardan birini ekleyin:

* #include "get_next_line.h"
* #include "get_next_line_bonus.h"

### Uygun dosyaları kullanarak *.c kodunuzu derleyin:

* cc -Wall -Wextra -Werror *.c get_next_line.c get_next_line_utils.c

### Bonus versiyonunu kullanmak için:

* cc -Wall -Wextra -Werror main.c get_next_line_bonus.c get_next_line_utils_bonus.c

Bonus bölümde fonksiyonumuz birden fazla ***File Descriptor*** ile çalışabilir 
