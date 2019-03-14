//flat_rate:2 === 'under 4 pounds' value
//flat_rate:3 === '4 to 6 pounds' value
//flat_rate:4 === 'seven Pounds and Up' value

add_filter( 'woocommerce_package_rates', 'bbloomer_woocommerce_tiered_shipping', 9999, 2 );
   
function bbloomer_woocommerce_tiered_shipping( $rates, $package ) {
     
    if ( WC()->cart->cart_contents_weight < 4 ) {
      
        if ( isset( $rates['flat_rate:5'] ) ) unset( $rates['flat_rate:6'], $rates['flat_rate:8'] );
       
    } elseif ( WC()->cart->cart_contents_weight < 7 ) {
       
        if ( isset( $rates['flat_rate:5'] ) ) unset( $rates['flat_rate:5'], $rates['flat_rate:8'] );
       
    } else {
       
        if ( isset( $rates['flat_rate:5'] ) ) unset( $rates['flat_rate:5'], $rates['flat_rate:6'] );
       
    }
   
  return $rates;
   
}