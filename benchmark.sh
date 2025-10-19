#!/bin/bash

# Push_swap executable
PS="./push_swap"

# Fonksiyon: rastgele sayı üret
generate_numbers() {
    COUNT=$1
    shuf -i 0-1000 -n $COUNT
}

# Fonksiyon: push_swap çalıştır ve hamle sayısını al
test_numbers() {
    NUMS="$1"
    OPS=$($PS $NUMS | wc -l)
    echo $OPS
}

echo "----------------------------"
echo "Testing 100 numbers..."
NUMS_100=$(generate_numbers 100)
OPS_100=$(test_numbers "$NUMS_100")
echo "Operations performed: $OPS_100"

echo "Testing 500 numbers..."
NUMS_500=$(generate_numbers 500)
OPS_500=$(test_numbers "$NUMS_500")
echo "Operations performed: $OPS_500"

echo "----------------------------"
echo "Validation results:"

# Minimal project validation
if [ $OPS_100 -lt 1100 ] && [ $OPS_500 -lt 8500 ]; then
    echo "Minimal validation 80%: PASSED"
else
    echo "Minimal validation 80%: FAILED"
fi

# Diğer seçenekler
if [ $OPS_100 -lt 700 ] && [ $OPS_500 -lt 11500 ]; then
    echo "Option 2: PASSED"
else
    echo "Option 2: FAILED"
fi

if [ $OPS_100 -lt 1300 ] && [ $OPS_500 -lt 5500 ]; then
    echo "Option 3: PASSED"
else
    echo "Option 3: FAILED"
fi
