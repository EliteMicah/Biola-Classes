<!DOCTYPE html>
<html lang="en">
<head> 
    <title> PHP Food Group </title>
</head>
<body>
<?php
    $name = $_POST["customer"];
    $order1 = $_POST["aqty"];
    $order2 = $_POST["mqty"];
    $order3 = $_POST["dqty"];
    
    echo "Welcome ", $customer, "! You ordered:";
?>
    <table>
        <tr>
            <th> <?php echo $order1, " Appetizer(s)" ?> </th>
            <th> <?php echo $order2, " Main Dish(es)" ?> </th>
            <th> <?php echo $order3, " Dessert(s)" ?> </th>
        </tr>
        <tr>
            <td> 
                <img src="https://i.pinimg.com/736x/6a/6f/08/6a6f0889e7fa602f79f9a86a585db11f.jpg" width="25%" height="50%"/>
            </td>
            <td> 
                <img src="https://i.pinimg.com/550x/0b/fd/17/0bfd17d30d48bb991a3eebddf89e9b44.jpg" width="25%" height="50%"/>
            </td>
            <td> 
                <img src="https://i.pinimg.com/345x/e5/ab/a7/e5aba778c56fa7b246872fae1094f222.jpg" width="25%" height="50%"/>
            </td>
        </tr>
    </table>
    <div>
        <?php
            $total1 = 0;
            $total2 = 0;
            $total3 = 0;
            $result = 0;
            
            if ($order1 != 0) {
                $total1 = 45 * $order1;
            }
            if ($order2 != 0) {
                $total2 = 135 * $order2;
            }
            if ($order3 != 0) {
                $total3 = 65 * $order3;
            }
            $result = $total1 + $total2 + $total3;
            echo "Your total cost is: ", $result;
        ?>
    </div>
</body>
</html>
