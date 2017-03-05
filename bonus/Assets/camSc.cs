using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class camSc : MonoBehaviour {
	GameObject li1 = null;
	GameObject li2 = null;
	public GameObject nand;
	public GameObject and;
	public GameObject nor;
	public GameObject or;
	public GameObject xor;
	public GameObject inp;
	public GameObject ligh;
	public GameObject inv;
	GameObject tmp;
	bool take = false;
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		Ray ray = Camera.main.ScreenPointToRay (Input.mousePosition);
		RaycastHit hit;

		if (Input.GetKey (KeyCode.Escape))
			Application.Quit();

		if (Input.GetKey (KeyCode.LeftArrow)) {
			if (this.transform.position.x > -13)
				this.transform.Translate (Vector3.left * Time.deltaTime * 5);
		}
		if (Input.GetKey (KeyCode.RightArrow)) {
			if (this.transform.position.x < 12)
				this.transform.Translate (Vector3.right * Time.deltaTime * 5);
		}
		if (Physics.Raycast (ray, out hit) && Input.GetKeyDown (KeyCode.D) && hit.collider.tag != "cantDel") {
			if (hit.collider.transform.parent == null) {
				if (hit.collider.gameObject.GetComponent ("door") != null) {
					if (hit.collider.gameObject.GetComponent<door> ().retLi ("press (1)") == false &&
					    hit.collider.gameObject.GetComponent<door> ().retLi ("") == false)
						Destroy (hit.collider.gameObject);
				} else if (hit.collider.gameObject.GetComponent ("buttonSc") != null) {
					if (hit.collider.gameObject.GetComponent<buttonSc> ().getLi () == null)
						Destroy (hit.collider.gameObject);
				}
			} else {
				if (hit.collider.transform.parent.gameObject.GetComponent ("door") != null) {
					if (hit.collider.transform.parent.gameObject.GetComponent<door> ().retLi ("press (1)") == false &&
						hit.collider.transform.parent.gameObject.GetComponent<door> ().retLi ("") == false)
						Destroy (hit.collider.transform.parent.gameObject);
				} else if (hit.collider.transform.parent.gameObject.GetComponent ("buttonSc") != null) {
					if (hit.collider.transform.parent.gameObject.GetComponent<buttonSc> ().getLi () == null)
						Destroy (hit.collider.transform.parent.gameObject);
				}
			}
		}
		if (Physics.Raycast(ray, out hit) && Input.GetButtonDown("Fire1") && hit.collider.tag == "canAdd" && take == false)
		{
			take = true;
			if (hit.collider.name == "NAND")
				tmp = Instantiate (nand, hit.transform.position, Quaternion.Euler (Vector3.zero));
			if (hit.collider.name == "AND")
				tmp = Instantiate (and, hit.transform.position, Quaternion.Euler (Vector3.forward * -1 * 90	));
			if (hit.collider.name == "NOR")
				tmp = Instantiate (nor, hit.transform.position, Quaternion.Euler (Vector3.zero));
			if (hit.collider.name == "OR")
				tmp = Instantiate (or, hit.transform.position, Quaternion.Euler (Vector3.zero));
			if (hit.collider.name == "XOR")
				tmp = Instantiate (xor, hit.transform.position, Quaternion.Euler (Vector3.zero));
			if (hit.collider.name == "Input")
				tmp = Instantiate (inp, hit.transform.position, Quaternion.Euler (Vector3.zero));
			if (hit.collider.name == "INV")
				tmp = Instantiate (inv, hit.transform.position, Quaternion.Euler (Vector3.zero));
			if (hit.collider.name == "LIGHT")
				tmp = Instantiate (ligh, hit.transform.position, Quaternion.Euler (Vector3.zero));
			
		}
		if (Physics.Raycast(ray, out hit) && Input.GetButton("Fire1") && take)
		{
			Vector3 tmpv = hit.point;
			tmpv.y = 0.15f;
			tmp.transform.position = tmpv;
		}
		if (Physics.Raycast(ray, out hit) && Input.GetButtonUp("Fire1") && take)
		{
			take = false;
			tmp = null;
		}
		if (Input.GetButtonDown("Fire1") && Physics.Raycast (ray, out hit)) {
			if (hit.collider.tag == "button") {
				hit.collider.GetComponent<buttonSc> ().setInput ();
			}
		}
		if (Input.GetButton("Fire2") && Physics.Raycast (ray, out hit)) {
			if (hit.collider.tag == "canMove" || hit.collider.name.Contains("Input")) {
				Vector3 tmp = hit.point;
				tmp.y = 0.15f;
				hit.collider.transform.position = tmp;
			}
		}
		if (Input.GetKeyDown (KeyCode.A) && Physics.Raycast (ray, out hit)) {
			if (hit.collider.tag == "button") {
				if (hit.collider.gameObject.GetComponent<buttonSc>().getLi() == null)
					li1 = hit.collider.gameObject;
			} else if (hit.collider.tag == "buttonA")
			{
				li2 = hit.collider.gameObject;
			}
		}
		if (Input.GetKeyDown (KeyCode.Z) && Physics.Raycast (ray, out hit)) {
			if (hit.collider.tag == "button") {
				if (hit.collider.gameObject.GetComponent<buttonSc> ().getLi () != null) {
					GameObject tmp;
					tmp = hit.collider.gameObject.GetComponent<buttonSc> ().getLi ();
					if (tmp.name.Contains ("light")) {
						tmp.GetComponentInParent<recept> ().setLi (null);
						tmp.GetComponentInParent<recept> ().setGood (false);
						hit.collider.gameObject.GetComponent<buttonSc> ().resetLi ();
					} else {
						tmp.GetComponentInParent<door> ().setBool (tmp, false);
						tmp.GetComponentInParent<door> ().setGood (false);
						tmp.GetComponentInParent<door> ().setFLi (tmp.name);
						hit.collider.gameObject.GetComponent<buttonSc> ().resetLi ();
						tmp.GetComponentInParent<door> ().setLi ("");
					}
				}
			}
		}
		if (li1 != null && li2 != null) {
			if (li2.name.Contains("light") != true && li2.GetComponentInParent<door> ().retLi (li2.name) == false) {
				li1.GetComponent<buttonSc> ().setLiaison (li2);
				li2.GetComponentInParent<door> ().setLi (li2.name);
				li2.GetComponentInParent<door> ().setGood (true);
			}
			if (li2.name.Contains ("light") == true && li2.GetComponentInParent<recept> ().retLi("") == false) {
				li1.GetComponent<buttonSc> ().setLiaison (li2);
				li2.GetComponentInParent<recept> ().setLi (li1);
				li2.GetComponentInParent<recept> ().setGood (true);
			}
			li1 = null;
			li2 = null;
		}
	}
		
}
