using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class image : MonoBehaviour {
	public Image asd;
	// Use this for initialization
	void Start () {
		//change Image Texture Type ->Sprite
		asd.sprite = Resources.Load<Sprite> ("Image/minion")as Sprite; 
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
