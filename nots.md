*./push_swap " " => Error basması lazım
*./push_swap "000000000000000000000000000000000000000000000009" 
 ./push_swap "3 23058430092136939517" maks in değerini işleyebilirsin sadece bunda strcmp gibi bir şeyle bakabilirsin yada overflow değerde programı sonlandır
 *valgrind --leak-check=full ./push_swap "3 1 1" => leak çıktı
 *valgrind --leak-check=full ./push_swap "3 1 a" => leak çıktı
 *valgrind --leak-check=full ./push_swap "3 5.2" => leak çıktı
 k1m04s02% ./push_swap -2147483648 => makroyu doığru çek lutfen
	Error