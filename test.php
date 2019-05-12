<?php
$data_types=["long","char*"];
$classes=["list"=>["ArrayList","std::vector","LinkedList","std::forward_list","DoublyLinkedList","std::list"],"map"=>["TreeMap","std::map","HashMap","std::unordered_map"],"set"=>["TreeSet","std::set","HashSet","std::unordered_set"]];
foreach($data_types as $dataType) {
	foreach($classes as $adt=>$entries) {
		foreach($entries as $class) {
			for($i=0; $i<10; $i++) {
				$output = array();
				exec("./benchmark ".$adt." ".$class." ".$dataType, $output);
				echo $class."\t".$dataType.$output[0]."\n";
			}
		}
	}
}

