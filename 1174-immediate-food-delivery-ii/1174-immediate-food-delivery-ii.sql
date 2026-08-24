SELECT ROUND(
    SUM(CASE WHEN first_order = pref_date THEN 1 ELSE 0 END) * 100.0 / COUNT(*),
    2
) AS immediate_percentage
FROM (
    SELECT customer_id,
           MIN(order_date) AS first_order,
           MIN(customer_pref_delivery_date) AS pref_date
    FROM Delivery
    GROUP BY customer_id
) t;
