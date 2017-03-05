using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class recept : MonoBehaviour {
	bool li = false;
	bool state = false;
	GameObject gLi = null;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		if (gLi != null) {
			if (gLi.GetComponent<buttonSc>().retState() == true) {
				this.transform.Find ("light").transform.Find ("rLight").GetComponent<Light> ().enabled = true;
			} else
				this.transform.Find ("light").transform.Find ("rLight").GetComponent<Light> ().enabled = false;
		}
	}

	public bool retLi(string name)
	{
		return (li);
	}

	public void setLi(GameObject obj)
	{
		gLi = obj;
		state = true;
	}

	public void setGood(bool s)
	{
		state = s;
	}
}